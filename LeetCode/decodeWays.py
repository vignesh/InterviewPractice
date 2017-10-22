class Solution(object):
    def numDecodings(self, s):
        """
        :type s: str
        :rtype: int
        """
        n = len(s)
        if n == 0 or s[0] == "0":
            return 0
        if n == 1:
            return 1
        pre1 = 1
        pre2 = 1
        i = 1
        while i < n:
            cur = 0
            first = int(s[i])
            second = int(s[i-1:i+1])
            if first >= 1 and first <= 9:
                cur += pre1
            if second >= 10 and second <= 26:
                cur += pre2
            pre2 = pre1
            pre1 = cur
            i+=1
        return cur