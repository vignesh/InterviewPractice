class Solution(object):
    def moveZeroes(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        nonZeroCounter = 0
        for counter in range(len(nums)):
            if (nums[counter] != 0):
                temp = nums[nonZeroCounter]
                nums[nonZeroCounter] = nums[counter]
                nums[counter] = temp
                nonZeroCounter+=1