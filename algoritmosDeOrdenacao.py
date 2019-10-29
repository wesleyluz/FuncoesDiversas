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
'''O método ordenar recebe uma colecão
realiza ordenacão na colecão
retorna colecão após ordenação
'''

from math import floor
import random

class InsertionSort(object):
    def ordenar(self, colecao):        
        for j in range(1, len(colecao)):
            key = int(colecao[j]['weight'])
            i = j-1
            while i>-1 and key < int(colecao[i]['weight']):
                colecao[i+1] =colecao[i]
                i = i-1            
        return colecao

class QuickSort(object):
    def ordenar(self, colecao,low, high, t_pivo):
        #return quickSort(colecao, 0, len(colecao)-1)
        if low < high:     
            # pi is partitioning index, arr[p] is now 
            # at right place 
            pi = self.partition(colecao, low, high, t_pivo) 
    
            # Separately sort elements before 
            # partition and after partition 
            self.ordenar(colecao, low, pi-1, t_pivo) 
            self.ordenar(colecao, pi+1, high, t_pivo)
            
            return colecao
        
    def partition(self, colecao, low, high, t_pivo):                               
        if t_pivo == 2: #aleatory pivot
            randIndex = random.randint(low, high)
            colecao[randIndex], colecao[high] = colecao[high], colecao[randIndex]
        else:
            mid = int((low+high)/2)
            a = int(colecao[low]['weight'])
            b = int(colecao[mid]['weight'])
            c = int(colecao[high]['weight'])

            if a<b:
                if b<c:
                    medianaIndex = mid
                elif a<c:
                    medianaIndex = high
                else:
                    medianaIndex = low
            else:
                if c<b:
                    medianaIndex = mid
                elif c<a:
                    medianaIndex = high
                else:
                    medianaIndex = low
            colecao[medianaIndex], colecao[high] = colecao[high], colecao[medianaIndex]
        pivot = colecao[high] # pivot]
        i = ( low-1 )  # index of smaller element 
        for j in range(low , high):     
            # If current element is smaller than or 
            # equal to pivot 
            if int(colecao[j]['weight']) <= int(pivot['weight']):             
                # increment index of smaller element 
                i = i+1 
                colecao[i],colecao[j] = colecao[j], colecao[i] 
        colecao[i+1], colecao[high] = colecao[high], colecao[i+1]
        return (i+1) 

class ShellSort(object):
    def ordenar(self, colecao):
        subColecaoCount = len(colecao)/2
        while subColecaoCount > 0:
            for startposition in range(int(subColecaoCount)):
                self.gapInsertionSort(colecao, startposition, int(subColecaoCount))
            subColecaoCount = subColecaoCount//2
        return colecao
    def gapInsertionSort(self, colecao, start, gap):
        for i in range(start+gap, len(colecao), gap):
            currentValue = colecao[i]
            position = i
            while position >= gap and int(colecao[position-gap]['weight'])>int(currentValue['weight']):
                colecao[position] = colecao[position-gap]
                position = position-gap
            colecao[position] = currentValue

class HeapSort(object):
    def ordenar(self, colecao):
        n = len(colecao)

        for i in range(n, -1, -1):
            self.heapify(colecao, n, i)

        for i in range(n-1, 0, -1):
            colecao[i], colecao[0] = colecao[0], colecao[i]
            self.heapify(colecao, i, 0)
        
        return colecao
    
    def heapify(self, colecao, n, i):
        largest = i

        l = 2 * i + 1
        r = 2 * i + 2

        if l < n and int(colecao[i]['weight']) < int(colecao[l]['weight']):
            largest = l
        if r < n and int(colecao[largest]['weight']) < int(colecao[r]['weight']):
            largest = r        
        if largest != i:
            colecao[i], colecao[largest] = colecao[largest], colecao[i]
            self.heapify(colecao, n, largest)

class SelectSort(object):
    def ordenar(self, colecao):
        for i in range(len(colecao)):
            min = i
            for j in range(i+1, len(colecao)):
                if int(colecao[min]['weight'])>int(colecao[j]['weight']):
                    min = j
            colecao[i], colecao[min] = colecao[min], colecao[i]
        return colecao

class CountSort(object):
    def ordenar(self, colecao):
        ran_val = self.searchMaxMin(colecao)
        return self.countSort(colecao, ran_val)
    def countSort(self, colecao, ran_val):
        m = ran_val[0] - ran_val[1] + 1
        count = [0] * m                
        output = [0]*len(colecao)
        for i in range(0, len(colecao)):
            count[int(colecao[i]['weight']) - ran_val[1]]+=1
        for i in range(1, len(count)):
            count[i] += count[i-1]
        for i in range(len(colecao)-1, -1, -1):
            output[count[int(colecao[i]['weight']) - ran_val[1]] - 1] = colecao[i]
            count[int(colecao[i]['weight']) - ran_val[1]]-=1
        for i in range(0, len(colecao)):
            colecao[i] = output[i]       
        return colecao

    def searchMaxMin(self, colecao):
        max_min = [int(colecao[0]['weight']), int(colecao[0]['weight'])]
        for i in colecao:
            if max_min[0] < int(i['weight']):
                max_min[0] = int(i['weight'])
            elif max_min[1] > int(i['weight']):
                max_min[1] = int(i['weight'])
        return max_min

class MergeSort(object):
    def ordenar(self, colecao):
        return self.mergeSort(colecao)

    def mergeSort(self, colecao):
        if len(colecao) >1: 
            mid = len(colecao)//2 #Finding the mid of the array 
            L = colecao[:mid] # Dividing the array elements  
            R = colecao[mid:] # into 2 halves 
    
            self.mergeSort(L) # Sorting the first half 
            self.mergeSort(R) # Sorting the second half 
    
            i = j = k = 0
            
            # Copy data to temp arrays L[] and R[] 
            while i < len(L) and j < len(R): 
                if int(L[i]['weight']) < int(R[j]['weight']): 
                    colecao[k] = L[i] 
                    i+=1
                else: 
                    colecao[k] = R[j] 
                    j+=1
                k+=1
            
            # Checking if any element was left 
            while i < len(L): 
                colecao[k] = L[i] 
                i+=1
                k+=1
            
            while j < len(R): 
                colecao[k] = R[j] 
                j+=1
                k+=1
        return colecao