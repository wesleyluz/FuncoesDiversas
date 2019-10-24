
import tensorflow as tf
import matplotlib.pyplot as plt
import numpy as np
from sklearn.metrics import confusion_matrix
import os
import shutil
import random
from glob import glob

def graphicPlot(name, history):
	
	plt.clf()
	
	plt.title(name)
	plt.plot(history.history['acc'])
	plt.plot(history.history['val_acc'])
	plt.ylabel('accuracy')
	plt.xlabel('epoch')
	plt.legend(['train_accuracy', 'val_accuracy'], loc = 'best')
	plt.savefig('accuracy_{}.png'.format(name))

	plt.clf()

	plt.title(name)
	plt.plot(history.history['loss'])
	plt.plot(history.history['val_loss'])
	plt.ylabel('loss')
	plt.xlabel('epoch')
	plt.legend(['train_loss', 'val_loss'], loc = 'best')
	plt.savefig('loss_{}.png'.format(name))


def save_array(name, features):
	np.save(name, features)

def load_array(name):
	array = np.load(name)
	return array

def results(y_test, y_get):
    matrix = confusion_matrix(y_test, y_get)
    tn = matrix[0,0]
    tp = matrix[1,1]
    fp = matrix[0,1]
    fn = matrix[1,0]

    p = tp/(tp + fp)
    s = tp/(tp + fn)
    e = tn/(tn + fp)
    acc = (tp + tn) / (tp + tn + fp + fn)

    return tn, tp, fp, fn, s, p, e, acc

def rename_files(name, path, formato, n):
	i=n

	for filename in os.listdir(path):
		dst = name + str(i) + formato

		src = path + "/" + filename

		dst = path + "/" + dst

		os.rename(src, dst)

		i = i+1

def create_dir(path, n = 1):
	for i in range(1, n+1):
		name = path + str(i)
		os.mkdir(name)

def get_file_list(input_dir, formato):
    return glob(input_dir + "/*." + formato)

def get_random_files(file_list, N):
    return random.sample(file_list, N)

def copy_files(random_files, input_dir, output_dir):
    for file in random_files:
        shutil.move(os.path.join(input_dir, file), output_dir)

def main(input_dir, output_dir, N):
    file_list = get_file_list(input_dir)
    random_files = get_random_files(file_list, N)
    copy_files(random_files, input_dir, output_dir)

def move(name, subdir_nome, formato):
	j = 1
	while(j<6):
		files = u.get_file_list(name, formato)
		print(len(files))
		subdir_name = subdir_nome + str(j)
		i = 0
		for f in files:
			#f2 = "Non-glaucoma3/" + f
			shutil.move(f, subdir_name)
			i += 1
			if(i >=72):
				break
		j += 1