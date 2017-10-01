class Solution(object):
    def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        elementMap = {}
        majorityLimit = len(nums)/2
        for num in nums:
            if num not in elementMap:
                elementMap[num] = 1
            else:
                elementMap[num] +=1
                
            if elementMap[num] > majorityLimit:
                return num 