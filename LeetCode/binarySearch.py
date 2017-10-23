#iterative
def binary_search(elements, target):
    if not elements or len(elements) <= 0:
        return -1
    left  = 0
    right  = len(elements) - 1
    while left <= right:
        middle = (left + right)/2
        if elements[middle] > target:
            right = middle - 1
        elif elements[middle] < target:
            left = middle + 1
        else:
            return middle
    return -1

#recrusive 
def binary_search(elements, target, left, right):
    #base case
    if right >= 1:
        middle = (left + right)//2
        #middle = left + (right - 1)/2
        if elements[middle] > target:
            return binary_search(elements, target, left, middle-1)
        elif elements[middle] < target:
            return binary_search(elements, target, middle+1, right)
        else:
            return middle
    else:
        return -1