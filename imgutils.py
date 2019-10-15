import cv2
import glob

'''
    Funções utilitárias para processamento de imagens
'''

def load_imgs(path):
    '''
        Carrega todas as imagens em dado caminho para dentro de img_array (retorna um array de imagens)
    '''

    img_array = []

    for img in glob.glob(path):
      img_read = cv2.imread(img)
      img_array.append(img_read)

    return img_array