class Solution(object):
    def missingNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        lengthNums = len(nums)
        totalSum = lengthNums * (lengthNums + 1) / 2
        for num in nums:
            totalSum -= num
        return totalSum