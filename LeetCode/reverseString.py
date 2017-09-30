class Solution(object):
    def reverseString(self, s):
        """
        :type s: str
        :rtype: str
        """
        reverse = ""
        for char in s:
            reverse = char + reverse
        return reverse