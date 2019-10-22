import sys, os, glob
import cv2

"""
  Função que carrega vários arquivos de certo tipo dentro de um diretorio
  Retorna uma lista com caminhos de todos os arquivos (caminho do diretorio + nome do arquivo)
  path_in: Caminho da pasta com os arquivos
  file_ext: extensão do arquivo
"""

def carregar_arquivos(path_in, file_ext):
	global_paths = os.path.join(path_in, '*'+file_ext)
	file_paths = glob.glob(global_paths)

	return file_paths

"""
Exemplo:
	Exibir cada imagem em determinada pasta
"""
if __name__ == '__main__':
	# pasta = 'C:/Users/Grabriloso/Desktop/Test_10-20-2019'
	pasta = '.' #	'.' significa diretorio atual
	ext = '.png'

	arquivos = carregar_arquivos(pasta, ext)

	for file in arquivos:
		imagem = cv2.imread(file)
		cv2.imshow(file, imagem)
		cv2.waitKey(0)
