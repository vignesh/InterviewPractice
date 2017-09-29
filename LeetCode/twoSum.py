class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        mapping = {}
        finalArray = []
        counter = 0
        for number in nums:
            complement = target - number
            if complement in mapping:
                finalArray.append(mapping[complement])
                finalArray.append(counter)
                return finalArray
            mapping[number] = counter
            counter+=1
        return finalArray