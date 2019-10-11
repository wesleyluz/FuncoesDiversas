def Shell_sort(alist):
	tam = len(alist)
	h = 1 
	while h < len(alist):
		h = (3*h)+1
	while h > 0:
		h = (h-1)//3 #atualiza o valor de h
		for i in range (h,tam):
			temp = alist[i]
			j = i
			while alist[j-h]>temp:
				alist[j] = alist[j-h]
				j = j-h
				if j<h:
					break
			alist[j] = temp

alist = [6,4,2,5,7,0,9,8,1,3]
Shell_sort(alist)
print("A lista:",alist)