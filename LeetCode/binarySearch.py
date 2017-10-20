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