def bubbleSort(arr):
    for i in range(len(arr)): 
        for j in range(0, len(n)-i-1): 
            if arr[j] > arr[j+1] : 
                arr[j], arr[j+1] = arr[j+1], arr[j] 

if __name__ == "__main__":
    # Driver code to test above 
    arr = [64, 34, 25, 12, 22, 11, 90] 
  
    bubbleSort(arr) 
  
    print ("Sorted array is:") 
    for i in range(len(arr)): 
        print (f"{arr[i]}"),  
