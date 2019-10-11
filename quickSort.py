# "Randomized" quicksort. The function randomPartition() gets a random index and switches its position with the last
#  index, using the last element (random) as the pivot.
def quickSort(array, start=0, end=-1):
    if end == -1:
        end = len(array) - 1
    if start < end:
        pivot = randomPartition(array, start, end)

        quickSort(array, start, pivot - 1)
        quickSort(array, pivot + 1, end)

    return array


def partition(array, start, end):
    # uses the last element as the pivot.
    pivot = end
    i = start - 1
    j = start
    while j < end:
        if array[j] <= array[pivot]:
            i += 1
            array[i], array[j] = array[j], array[i]
        j += 1
    array[pivot], array[i + 1] = array[i + 1], array[pivot]

    # returns the new pivot position:
    return i + 1


# Chooses a random index in the array and switches it with the element at the last position,
#  then calls the partition() function.
def randomPartition(array, start, end):
    pivot = random.randint(start, end)
    array[pivot], array[end] = array[end], array[pivot]
    return partition(array, start, end)