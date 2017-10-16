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