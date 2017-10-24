# >>> lst = [[1], 2, [[3,4], 5], [[[]]], [[[6]]], 7, 8, []]
# >>> flatten(lst)
# [1, 2, 3, 4, 5, 6, 7, 8]

#recursive solution
def flattenList(l):
	#sum [] joins lists in python
	return sum(([x] if not isinstance(x,list) else flattenList(x) for x in l), [])

#iterative solution
def flattenList2(l):
	i = 0
	while i < len(l):
		while True:
			try:
				#checks if there are more nested elements and if last element
				# print l[i:i+1]
				# print l[i]
				# print "----"
				l[i:i+1] = l[i]
			except (TypeError, IndexError):
				# print l[i:i+1]
				# print "****" 
				break
		i+=1
	return l

#genertor method will need to be converted to list
#generator calcaultes on the fly, and the yield method immeaditely returns the value
def flattenList3(lst):
     for x in lst:
         if isinstance(x, list):
             for x in flattenList3(x):
                 yield x
         else:
             yield x

if __name__ == "__main__":
	lst = [[1], [2], [[3,4], 5], [[[]]], [[[6]]], 7, 8, []]
	print flattenList(lst)
	print flattenList2(lst)
	print list(flattenList3(lst))