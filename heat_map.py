from keras.models import load_model
from keras.preprocessing import image
from keras.models import Model
from keras.applications.vgg16 import preprocess_input, decode_predictions
from glob import glob
import scipy as sp
import numpy as np
import matplotlib.pyplot as plt
from keras import backend as K

image_files = glob('Glaucoma-HRF/test/*/*.jpg')

base_model = load_model('model_0.8822724161533196_1f38e.h5')
base_model.summary()

features = base_model.get_layer(name='conv2d_1')

model = Model(inputs=base_model.input, outputs=features.output)

final_dense = base_model.get_layer('dense_3')

W = final_dense.get_weights()[0]

img = image.load_img(np.random.choice(image_files), target_size=(224, 224))
x = preprocess_input(np.expand_dims(img, 0))
fmaps = model.predict(x)[0]

pred = base_model.predict(x)

argmax = np.argmax(pred[0])

output = model.output[:, argmax]

last_conv_layer = model.get_layer('conv2d_1')

grads = K.gradients(output, last_conv_layer.output)[0]

pooled_grads = K.mean(grads, axis=(0, 1, 2))

iterate = K.function([model.input], [pooled_grads, last_conv_layer.output[0]])

pooled_grads_value, conv_layer_output_value = iterate([x])

for i in range(512):
    conv_layer_output_value[:, :, i] *= pooled_grads_value[i]

plt.xlabel("Glaucoma {0:.2F}%".format(pred[0][0] *100))
plt.imshow(img)

heatmap = np.mean(conv_layer_output_value, axis=-1)
heatmap = np.maximum(heatmap, 0)
heatmap /= np.max(heatmap)
plt.matshow(heatmap, interpolation = 'bilinear')
plt.show()
