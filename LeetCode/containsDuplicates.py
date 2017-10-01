class Solution(object):
    def containsDuplicate(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        numberMap = {}
        for num in nums:
            if num not in numberMap:
                numberMap[num] = 1
            else:
                return True
        return False
        