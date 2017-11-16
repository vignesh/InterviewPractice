class Solution(object):
    def strStr(self, haystack, needle):
        """
        :type haystack: str
        :type needle: str
        :rtype: int
        """
        m = len(haystack)
        n = len(needle)
        if n > m:
            return -1
        if not n:
            return 0
        i = 0
        while i < m - n + 1:
            j = 0
            while j < n:
                if haystack[i+j] != needle[j]:
                    break
                j+=1
            if j == n:
                return i
            i+=1
        return -1