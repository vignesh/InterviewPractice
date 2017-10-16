class Solution(object):
    def rob(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        a = 0
        b = 0
        for i, num in enumerate(nums):
            if i % 2 == 0:
                a  = max(a+num, b)
            else:
                b = max(b+num, a)  
        return max(a,b)