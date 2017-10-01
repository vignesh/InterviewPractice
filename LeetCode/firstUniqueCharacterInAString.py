class Solution(object):
    def firstUniqChar(self, s):
        """
        :type s: str
        :rtype: int
        """
        index = -1
        occuranceMap = {}
        counter = 0
        for char in s:
            if char not in occuranceMap:
                occuranceMap[char] = [1, counter]
            else:
                occuranceMap[char][0] +=1
            counter+=1
        
        maxIndex = len(s)
        for key, value in occuranceMap.iteritems():
            if value[0] == 1 and  value[1] < maxIndex:
                maxIndex = value[1]
                index = value[1]
        return index
        