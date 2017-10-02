class Solution(object):
    def intersect(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: List[int]
        """
        setNums1 = set(nums1)
        intersectArray = []
        for num in nums2:
            if num in setNums1:
                intersectArray.append(num)
                
        return intersectArray
        