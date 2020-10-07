#-*- coding: utf-8 -*-

import matplotlib.pyplot as plt
import math
import numpy as np
import cv2

def menu():
	print("Bem vindo ao Trabalho 3 de PI")
	print("Este trabalho foi feito por Lisle Farai de Paiva")

def showImage(img, title, file_name, cmap):

	plt.imshow(img,  cmap = cmap)
	plt.axis('off')
	plt.title(title)
	plt.savefig(file_name)
	plt.show()



def negativeTransform(img_name):


	print("Reading Image from file...")
	img = cv2.imread(img_name, 0)

	rows = img.shape[0]
	cols = img.shape[1]


	print("Generating negative image...")
	for i in range(0, rows):
		for j in range(0, cols):
			s = 255 - img[i][j]
			img[i][j] = s

	return img

def gammaCorrection(img_name, G):

	print("Reading Image from file...")
	img = cv2.imread(img_name, 1)

	print("Generating gamma corrected image...")
	img = img/255

	correctedIMG = img**(1/G)

	correctedIMG = correctedIMG*255

	return correctedIMG 

def logTransform(c, pixel):

	output = c*math.log(float(1+pixel), 10)
	return output

def logTransformImage(img_name, outMax = 255, inMax = 255):

	print("Reading Image from file...")

	img = cv2.imread(img_name)

	print("Calculating c...")
	c = outMax/math.log(inMax+1, 10) 


	rows = img.shape[0]
	cols = img.shape[1]
	channel = img.shape[2]

	print("Generating log transformed image...")
	for i in range(0, rows):
		for j in range(0, cols):
			for k in range(0, channel):

				img[i][j][k] =  round(logTransform(c, img[i][j][k]))

	return img


def main():

	menu()

	grayImg = cv2.imread("cat.jpg", 0)

	print("1 - Negative Transformation\n")

	negImg = negativeTransform("cat.jpg")

	foto = np.hstack((grayImg, negImg))

	showImage(foto, "Imagem Original x Imagem Negativa", "negative.png", 'gray')


	print("2 - Gamma Correction")

	colorImg = cv2.imread("cat.jpg")/255

	smallGama = gammaCorrection("cat.jpg", 0.5)/255

	highGama = gammaCorrection("cat.jpg", 2)/255

	foto = np.hstack((smallGama, colorImg, highGama))

	showImage(foto, "G = 0.5 x Imagem Original (G=1) x G = 2", "gamma.png", 'hsv')

	print("3 - Logarithm Transformation")

	logImg = logTransformImage("cat.jpg")/255

	foto = np.hstack((colorImg, logImg))

	showImage(foto, "Imagem Original x Operador Logaritmico", "log.png" ,'hsv')



	
	





	



if __name__ == '__main__':
	main()