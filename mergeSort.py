def mergeSort(array, left=0, right=-1, arrayAux=None):
    # in the first execution, arrayAux will be none(null). arrayAux will be created and passed as
    # a parameter for the next executions.
    if right == -1:
        right = len(array) - 1
    if arrayAux is None:
        arrayAux = array[:]
    half = left + (right - left) // 2
    # checking whether the received array or subarray has more than one element.
    if left < right:
        mergeSort(array, left, half, arrayAux)
        mergeSort(array, half + 1, right, arrayAux)
        merge(array, left, right, half, arrayAux)

    return array


def merge(array, left, right, half, arrayAux):
    # cur variables will iterate through the array and make comparisons.
    # auxCur indicates the current position in arrayAux.
    leftCur = left
    leftEnd = half
    rightCur = half + 1
    rightEnd = right
    auxCur = left

    # while none of the subarrays have reached an end.
    while leftCur <= leftEnd and rightCur <= rightEnd:
        if array[leftCur] <= array[rightCur]:
            arrayAux[auxCur] = array[leftCur]
            leftCur += 1
        else:
            arrayAux[auxCur] = array[rightCur]
            rightCur += 1
        auxCur += 1

    # only executes when the right subarray has reached an end and the left one hasn't.
    while leftCur <= leftEnd:
        arrayAux[auxCur] = array[leftCur]
        auxCur += 1
        leftCur += 1

    # only executes when the left subarray has reached an end and the right one hasn't.
    while rightCur <= rightEnd:
        arrayAux[auxCur] = array[rightCur]
        auxCur += 1
        rightCur += 1

    # now copy every element of the sorted arrayAux to the original array.
    for i in range(len(array)):
        array[i] = arrayAux[i]

