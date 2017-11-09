
mergesort(array):
	if len(array) <= 1:
		return array

	middle = len(array)//2
	left = mergesort(array[:middle])
	right = mergesort(arra[middle:])
	merge(left, right)

merge(left, right):
	leftLen = len(left)
	rightLen = len(right)
	result = []
	i = 0
	j = 0
	while i < leftLen and j < rightLen:
		if left[i] <= right[j]:
			result.append(left[i])
			i+=1
		else:
			result.append(right[j])
			j+=1

	result += left[i:]
	result += right[j:]
	return result


