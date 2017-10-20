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

#ONlt good solution for sorted array, binary search
def twoSum(self, numbers, target):
    for i in range(len(numbers)-1):
        l = i+1
        r = len(numbers)-1
        complement = target - numbers[i]
        while l <= r:
            middle = l + (r-l) // 2
            if numbers[middle] == complement:
                #adding one to index, because anser requires not zero indexed
                return [i+1, middle+1]
            elif numbers[middle] < complement:
                l = middle+1
            else:
                r = middle-1