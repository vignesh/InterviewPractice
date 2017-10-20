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


class Solution(object):
    def twoSum(self, numbers, target):
        """
        :type numbers: List[int]
        :type target: int
        :rtype: List[int]
        """
        #given sorted array of numbers
        l = 0
        r = len(numbers)-1
        while l < r:
            sum2 = numbers[l] + numbers[r]
            if sum2 == target:
                #adding one to index, because anser requires not zero indexed
                return [l+1,r+1]
            elif target > sum2:
                l+=1
            else:
                r-=1