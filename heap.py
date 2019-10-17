'''
    Obs : não é o heapsort, é uma lista de heap, ou algo assim, a cada pop, retorna o menor elemento
'''
class Heap:
    def __init__(self):
        self.list = []

    def append(self, data):
        self.list.append(data)

    def pop(self, key):
        n = len(self.list)
        i = (n//2)
        if n == 0:
            raise KeyError("Heap is empty!")
        i -= 1
        while i >= 0:
            lson = i*2 + 1
            rson = lson + 1

            # garante que os nós analisados estão dentro da lista
            indexes = [x for x in [i, lson, rson] if x< n]
            nodes = [self.list[x] for x in indexes]

            # pega o menor dos nós e troca o pai
            smaller = min(nodes, key=key)
            idx_menor = indexes[nodes.index(smaller)] # pega o índice do menor

            # evita troca desnecessária
            if self.list[i] != smaller:
                aux = self.list[i]
                self.list[i] =  smaller
                self.list[idx_menor] = aux
            i -= 1
        return self.list.pop(0)