class Solution(object):
    def isPalindrome(self, s):
        """
        :type s: str
        :rtype: bool
        """
        re.sub('[^a-zA-Z]',"",s)
        s = s.lower()
        start = 0
        end = len(s)-1
        while start < end:
            if not s[start].isalnum():
                start+=1
            if not s[end].isalnum():
                end-=1
            if s[start] != s[end]:
                return False
            start+=1
            end-=1
        return True
        