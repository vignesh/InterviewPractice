#O(n^2) time
class Solution(object):
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        nums.sort()
        threeSums = []
        for i in range(len(nums)-2):
            current = nums[i]
            left = i+1
            right = len(nums)-1
            while left < right:
                if current+nums[left]+nums[right] == 0:
                    threeSums.append([current, nums[left], nums[right]])
                    while left < right and nums[left] == nums[left+1]:
                        left+=1
                    while left < right and nums[right] == nums[right-1]:
                        right-=1
                    left+=1
                    right-=1
                elif current+nums[left]+nums[right] < 0:
                    left+=1
                else:
                    right-=1
        return threeSums

#Method with hashmap
class Solution(object):
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        target  = 0
        nums.sort()
        finalArray = set()
        for i in range(len(nums)-2):
            current = nums[i]
            mapping = {}
            counter = 0
            for number in nums:
                complement = target - number - current
                if complement in mapping:
                    finalArray.add([current, complement, number])
                mapping[number] = counter
                counter+=1
        return finalArray