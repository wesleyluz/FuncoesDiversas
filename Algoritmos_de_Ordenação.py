'''
Introdução:
- Implementar algoritmo de ordenação que receba uma colecão
- A coleção é uma lista de arestas
- Para comparar o peso as arestas entre dois item da coleção basta usar a chave 'weight' (peso)
Exemplos:
- Modo convencional
colecao[i] operador de comparacao colecao[j]
colecao[i] < colecao[j]
- Modo que você vai usar
int(colecao[i]['weight']) operador de comparacao int(colecao[j]['weight'])
int(colecao[i]['weight']) < int(colecao[j]['weight'])
É nescessário converter o valor pra Interger no momento da comparação a fim de evitar erros
'''

# Sua classe algoritmo de ordenação precisar ter um método ordenar


import random, math

#======================================================================================#
#   							I N S E R T I O N
#======================================================================================#

class insertion_sort(object):
    def ordenar(self, colecao):
        for i in range(1, len(colecao)): # [i] percorrer da pos 1 até a última pos de colecao
            '''print('Vetor ',i,': %s' %colecao) #teste 0'''
            curNum = colecao[i] #coleção
            '''print('curNum = ',curNum) #teste 1'''
            for j in range (i-1,-1,-1):# [j] percorre da primeira pos
                '''print('[J] = ', j)'''
                if colecao[j]['weight']>curNum['weight']: # procura para frente até encontrar alguém menor que o atual num
                    temp = colecao[j+1]
                    colecao[j+1] =colecao[j]
                    colecao[j] = temp
                    '''
					print(colecao[j],' >= ',curNum, '= true')  #teste 2
					print('temp = ',temp)
					'''
                else:
                    colecao[j+1] = curNum
                    break
        return colecao
#======================================================================================#
#   					 		S E L E C T I O N
#======================================================================================#


class selection_sort(object):
    def ordenar(self,colecao):
        for i in range (0, len(colecao) - 1) :
            minIndex = i
            for j in range (i+1, len(colecao)):
                if colecao[j]['weight'] < colecao[minIndex]['weight']:
                    minIndex = j
                if minIndex != i:
                    colecao[i],colecao[minIndex] = colecao[minIndex], colecao[i]
        return colecao
#======================================================================================#
#   							 S H E L L S O R T
#======================================================================================#


class shell_sort(object):
    def ordenar(self,colecao):
        h=1
        for h in range (1, int(len(colecao)), 3*h+1):
            while (h>=1):
                h = int((h-1)/3) #fazer cast não dar prob de float
                i=h
                while (i<len(colecao)):
                    aux = colecao[i]
                    j=i
                    while (j >= h and int(aux['weight']) < int(colecao[j-h]['weight'])):
                        colecao[j] = colecao[j-h]
                        j = j-h
                    colecao[j] = aux
                    i = i+1
        h = h/2
        return colecao

#======================================================================================#
#   							H E A P S O R T
#======================================================================================#

class heap_sort(object):
	def ordenar(self,colecao):
		def buil_max_heap(colecao):

			for i in range (len(colecao)-1,0,-1):
				colecao[0], colecao[i] = colecao[i], colecao[0]
				self.max_heapify(colecao,index=0,size=1)

		return colecao

	def parent(i):
		return (i-1)//2

	def low(i):
		return 2*1+1

	def hi(i):
		return 2*i+2

	def buil_max_heap(colecao):
		length = len(colecao)
		start = parent(length-1)

		while start >= 0:
			max_heapify(colecao,index= start, size = length)
			start = start -1

	def max_heapify(colecao, index, size):
		l = low(index)
		r = hi(index)

		if (l<size and colecao[l]['weight'] >colecao[index]['weight']):
			largest = l 
		else:
			largest = index

		if (r < size and colecao[r]['weight'] >colecao[largest]['weight']):
			largest = r 
		if (largest != index):
			colecao[largest], colecao[index] = colecao[index], colecao[largest]
			max_heapify(colecao, largest, size)

#======================================================================================#
#   							C O U N T S O R T
#======================================================================================#
class count_sort(object):
	def ordenar(self,colecao):
		

		
		tamanho = int(len(colecao))
		maior = int(colecao[0]['weight'])
		menor = int(colecao[0]['weight'])

		for k in colecao:
			if int(k['weight']) > maior:
				maior = int(k['weight'])
			if int(k['weight']) < menor:
				menor = int(k['weight'])

		media = maior - menor +1
		A = [0]*media
		saida =[0]* tamanho
		

		# passo 1 ----> contagem do número de cada elemento do intervalo
		for i in range(0,tamanho):
			A[int(colecao[i]['weight'])-menor]+=1;

		#passo 2 -----> Agora será feito o complemento de casas de cada valor
		for i in range (1,int(len(A))):
			A[i] += A[i-1]

		#passo 3 -------->  alocação dos valores no vetor ordenado.
		for i in range(tamanho-1,-1,-1):
			saida [A[int(colecao[i]['weight'])-menor]-1] = colecao[i]			
			A[int(colecao[i]['weight']) - menor]-= 1
 
		#passo 4  --------> passar o conteúdo do vetor final para o vetor original.
		for i in range(0,tamanho):
			colecao[i] = saida[i]

		return colecao



#======================================================================================#
#   							M E R G E S O R T
#======================================================================================#

class merge_sort(object):
    def ordenar(self, colecao):
        if len(colecao) > 1:
            meio = int(len(colecao)/2)
            esquerda = colecao[:meio]
            direita = colecao[meio:]

            self.ordenar(esquerda)
            self.ordenar(direita)

            i = j = k = 0

            while i < len(esquerda) and j < len(direita):
                if int(esquerda[i]['weight']) < int(direita[j]['weight']):
                    colecao[k] = esquerda[i]
                    i+=1
                else:
                    colecao[k] = direita[j]
                    j+=1
                k+=1

            while i < len(esquerda):
                colecao[k] = esquerda[i]
                i+=1
                k+=1
            while j < len(direita):
                colecao[k] = direita[j]
                j+=1
                k+=1

            return colecao



#======================================================================================#
#   							Q U I C K S O R T
#======================================================================================#

#(pivo mediana)
class quick_sort_Mid(object):
    def ordenar(self, colecao):
        self.sort(colecao, 0, len(colecao) - 1)

        return colecao

    def sort(self, colecao, left, right):
        if left<right:
            p = self.partition(colecao, left, right)
            self.sort(colecao, left, p-1)
            self.sort(colecao, p + 1, right)

        
    def get_pivot(self, colecao, left, right):
        mid = (right + left) // 2
        pivot = right
        
        if int(colecao[left]['weight']) < int(colecao[mid]['weight']):
            if int(colecao[mid]['weight']) < int(colecao[right]['weight']):
                pivot = mid
        elif int(colecao[left]['weight']) < int(colecao[right]['weight']):
            pivot = left
        return pivot


    def partition(self, colecao, left, right):
        pindex = self.get_pivot(colecao, left, right)
        pvalue = colecao[pindex]
        colecao[pindex], colecao[left] = colecao[left], colecao[pindex]
        aux = left

        for i in range(left, right + 1):
            if int(colecao[i]['weight']) < int(pvalue['weight']):
                aux += 1
                colecao[i], colecao[aux] = colecao[aux], colecao[i]
        colecao[left], colecao[aux] = colecao[aux], colecao[left]

        return (aux)

#(pivo inicio)
class quick_sort_beg(object):
    def ordenar(self, colecao):
        self.sort(colecao, 0, len(colecao) - 1)

        return colecao

    def sort(self, colecao, left, right):
        if left<right:
            p = self.partition(colecao, left, right)
            self.sort(colecao, left, p-1)
            self.sort(colecao, p + 1, right)

        
    def get_pivot(self, colecao, left, right):
        pivot = right
        return pivot


    def partition(self, colecao, left, right):
        pindex = self.get_pivot(colecao, left, right)
        pvalue = colecao[pindex]
        colecao[pindex], colecao[left] = colecao[left], colecao[pindex]
        aux = left

        for i in range(left, right + 1):
            if int(colecao[i]['weight']) < int(pvalue['weight']):
                aux += 1
                colecao[i], colecao[aux] = colecao[aux], colecao[i]
        colecao[left], colecao[aux] = colecao[aux], colecao[left]

        return (aux)

#(pivo fim)
class quick_sort_end(object):
    def ordenar(self, colecao):
        self.sort(colecao, 0, len(colecao) - 1)

        return colecao

    def sort(self, colecao, left, right):
        if left<right:
            p = self.partition(colecao, left, right)
            self.sort(colecao, left, p-1)
            self.sort(colecao, p + 1, right)

        
    def get_pivot(self, colecao, left, right):
        pivot = left     
        return pivot


    def partition(self, colecao, left, right):
        pindex = self.get_pivot(colecao, left, right)
        pvalue = colecao[pindex]
        aux = left

        for i in range(left, right + 1):
            if int(colecao[i]['weight']) < int(pvalue['weight']):
                aux += 1
                colecao[i], colecao[aux] = colecao[aux], colecao[i]
        colecao[left], colecao[aux] = colecao[aux], colecao[left]

        return (aux)
	
