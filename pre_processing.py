# -*- coding: utf-8 -*-
import numpy as np
import math
import cv2
'''
Funções diversas de pré processamento
'''

def equalizacao(array_img):
    '''
        Recebe um array de imagens e retorna um array de imagens com o canal h (hsv) equalizado
    '''
    for i, img in enumerate(array_img):
        h, s, v = cv2.split(cv2.cvtColor(img, cv2.BGR2HSV))
        h       = cv2.equalizeHist(h)
        array_img[i]        = cv2.cvtColor(cv2.merge((h, s, v)), cv2.HSV2BGR)
    return array_img

def clahe(array_img, clip_limit = 3):
    '''
        Recebe um array de imagens e retorna um array de imagens com o canal l (lab) equalizado com CLAHE
    '''
    for i, img in enumerate(array_img):
        l, a, b = cv2.split(cv2.cvtColor(img, cv2.COLOR_BGR2LAB))
        clahe = cv2.createCLAHE(clipLimit = clip_limit, tileGridSize = (8, 8))
        l = clahe.apply(l_channel)
        result_image = cv2.merge((l, a_channel, b_channel))
        array_img[i] = cv2.cvtColor(result_image, cv2.COLOR_LAB2BGR)
    return array_img

def logenhance(array_img):
    '''
        Recebe um array de imagens e retorna um array de imagens com o filtro logaritimico aplicado
    '''
    for z, img in enumerate(array_img):
        b, g, r = cv2.split(img)
        rows, cols = b.shape

        logb = logenhancechannel(b, rows, cols)
        logg = logenhancechannel(g, rows, cols)
        logr = logenhancechannel(r, rows, cols)
    
        merged_channels = cv2.merge((logb, logg, logr))
        array_img[z] = merged_channels

    return array_img

def logenhancechannel(channel, rows, cols):
    '''
        Aplica o realce logaritmico em um canal
        #! performance horrível
    '''
    result = np.zeros((rows*cols), dtype = np.float32).reshape((rows, cols))

    gr = 255/math.log10(255)
    for i in range(rows):
        for j in range(cols):
            result[i, j] = gr * math.log10(channel[i, j] + 1)
    
    result = np.uint8(result)
    return result

def negative(array_img):
    '''
        Recebe um array de imagens e retorna um array de imagens com o filtro negativo aplicado
    '''
    for z, img in enumerate(array_img):
        b, g, r = cv2.split(img)
        rows, cols = b.shape

        negb = negativechannel(b, rows, cols)
        negg = negativechannel(g, rows, cols)
        negr = negativechannel(r, rows, cols)

        merged_channels = cv2.merge((negb, negg, negr))
        array_img[z] = merged_channels

    return array_img

def negativechannel(channel, rows, cols):]
    '''
        Aplica o realce negativo em um canal
    '''
    result = np.zeros((rows*cols), dtype = np.float32).reshape((rows, cols))

    for i in range(rows):
        for j in range(cols):
            result[i, j] = 255 - channel[i, j]
    
    result = np.uint8(result)
    return result
        