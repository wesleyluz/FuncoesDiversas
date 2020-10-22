import os
import shutil
import random

from keras.preprocessing.image import ImageDataGenerator, img_to_array, load_img
import numpy as np
import cv2
import glob


def get_file_list(input_dir):
    return [file for file in os.listdir(input_dir) if os.path.isfile(os.path.join(input_dir, file))]


def get_random_files(file_list, N):
    return random.sample(file_list, N)


def copy_files(random_files, input_dir, output_dir):
    for file in random_files:
        if file.endswith(".jpg"):
            shutil.copy(os.path.join(input_dir, file), output_dir)

def move_files(random_files, input_dir, output_dir):
    for file in random_files:
        if file.endswith(".jpg"):
            shutil.move(os.path.join(input_dir, file), output_dir)


def augmentation(input_dir_load, input_dir_save, qtd_per_image):
    datagen = ImageDataGenerator(
        shear_range=0.02,
        width_shift_range=0.1,
        rotation_range=2,
        height_shift_range=0.1,
        zoom_range=0.3,
        fill_mode='constant',
        horizontal_flip=True,
        cval=0
    )


    cont = 0
    for filename1 in os.listdir(input_dir_load):

        if filename1.endswith(".jpg"):
            cont += 1

            img = load_img(input_dir_load + "/" + filename1)
            x = img_to_array(img)
            x = x.reshape((1,) + x.shape)

            i = 0
            for batch in datagen.flow(x, save_prefix=filename1, save_to_dir=input_dir_save, save_format='jpg'):
                i += 1
                if qtd_per_image == i:
                    break


def main(input_dir, output_dir_train, output_dir_valid, output_dir_test, N1, N2):
    #validação
    file_list = get_file_list(input_dir)
    copy_files(file_list, input_dir, output_dir_train) #copia tudo para treino

    #retira a validação N1
    file_list = get_file_list(output_dir_train)
    random_files = get_random_files(file_list, N1)
    move_files(random_files, output_dir_train, output_dir_valid)

    # retira teste N2
    file_list = get_file_list(output_dir_train)
    random_files = get_random_files(file_list, N2)
    move_files(random_files, output_dir_train, output_dir_test)


glaucoma= 200
normal  = 255
perc_valid = 0.1
perc_test = 0.1


main('/Users/gb/Documents/bases/RIMONE-db-r2/1/',
     '/Users/gb/Documents/bases/RIMONE-db-r2_aug/train/1/',
     '/Users/gb/Documents/bases/RIMONE-db-r2_aug/valid/1/',
     '/Users/gb/Documents/bases/RIMONE-db-r2_aug/test/1/',
     int(glaucoma*perc_valid), int(glaucoma*perc_test))


main('/Users/gb/Documents/bases/RIMONE-db-r2/0/',
     '/Users/gb/Documents/bases/RIMONE-db-r2_aug/train/0/',
     '/Users/gb/Documents/bases/RIMONE-db-r2_aug/valid/0/',
     '/Users/gb/Documents/bases/RIMONE-db-r2_aug/test/0/',
     int(normal * perc_valid), int(normal * perc_test))


augmentation('/Users/gb/Documents/bases/RIMONE-db-r2_aug/train/1/',
             '/Users/gb/Documents/bases/RIMONE-db-r2_aug/train/1/',
            10)

augmentation('/Users/gb/Documents/bases/RIMONE-db-r2_aug/valid/1/',
             '/Users/gb/Documents/bases/RIMONE-db-r2_aug/valid/1/',
             10)


augmentation('/Users/gb/Documents/bases/RIMONE-db-r2_aug/train/0/',
             '/Users/gb/Documents/bases/RIMONE-db-r2_aug/train/0/',
             8)

augmentation('/Users/gb/Documents/bases/RIMONE-db-r2_aug/valid/0/',
             '/Users/gb/Documents/bases/RIMONE-db-r2_aug/valid/0/',
             8 )
