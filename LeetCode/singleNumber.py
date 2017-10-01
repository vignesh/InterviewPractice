class Solution(object):
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        numberDict = {}
        
        for n in nums:
            if n not in numberDict:
                numberDict[n] = 1
            else:
                numberDict.pop(n, None)
            
        for singleKeys, singleValues in numberDict.iteritems():
            return singleKeys
        