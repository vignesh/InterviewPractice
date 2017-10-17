class Solution(object):
    def intersection(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: List[int]
        """
        
        nums1=set(nums1)
        nums2=set(nums2)
        numMapping = {}
        result = []
        for num in nums1:
            if num not in numMapping:
                numMapping[num] = 0
        
        for num in nums2:
            if num in numMapping:
                result.append(num)
                    
        return result
        