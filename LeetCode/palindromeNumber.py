class Solution(object):
    def isPalindrome(self, x):
        """
        :type x: int
        :rtype: bool
        """
        divisor = 1
        while x/divisor >= 10:
            divisor *=10
        
        while  x != 0:
            lead = x % divisor
            end = x/10
            print lead
            print end
            
            if (lead != end):
                return False
        
            x = (x % divisor)/10
            divisor/=100
            
        return True
        
        