#O(NM), where N is number of words, and m is lenght of longest word
def longestCommonPrefix(words):
	prefix = words[0]
	for word in words[1:]:
		prefix = prefixMatch(prefix, word)
	return prefix

def prefixMatch(word1, word2):
	for i, char in enumerate(word2):
		if word1[i] != char:
			break
	return word1[:i-1]


#Dvide and Conquer Method, O(MN)
def longestCommonPrefix(words, low, high):
	if words[low] == word[high]:
		return words[low]

	if high > low:
		mid = (low + high)/2

		prefix1 = longestCommonPrefix(words, low, mid)
		prefix2 = longestCommonPrefix(words, mid, high)

	return prefixMatch(prefix1, prefix2)

def prefixMatch(prefix1, prefix2):
	len1 = len(prefix1)
	len2 = len(prefix2)
	i = 0
	j = 0
	while i < len1 and j < len2:
		if prefix1[i] != prefix2[j]:
			break
	return prefix1[:i]

#Divide and Conquer Solution iterative O(MN)
def longestCommonPrefix(words):
	minString = sort(words,key=len)
	prefix = ""
	low = 0
	high = len(minString)

	while low <= high:
		mid = (low + high)/2

		if (longestCommonPrefixHelper(words, minString, low, mid)):
			
			#update prefix
			prefix =  prefix + minString[low:mid-low-1]
			
			#make windown larger, check right side
			low = mid + 1

		#make window smaller, check left side
		else:
			high = mid -1

	return prefix

def longestCommonPrefixHelper(words, prefix, start, end):
	for word in words:
		j = start
		while j < end:
				if word[j] != prefix[j]:
					return False
			j+=1
	return True
	