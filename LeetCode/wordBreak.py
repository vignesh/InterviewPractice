#d[i] is True if there is a word in the dictionary that ends at ith index of s AND d is also True at the beginning of the word
"""
s = "leetcode"
words = ["leet", "code"]
d[3] is True because there is "leet" in the dictionary that ends at 3rd index of "leetcode"
d[7] is True because there is "code" in the dictionary that ends at the 7th index of "leetcode" AND d[3] is True
"""

class Solution(object):
    def wordBreak(self, s, wordDict):
        """
        :type s: str
        :type wordDict: List[str]
        :rtype: bool
        """
        d = [False] * len(s)
        for i in range (len(s)):
            for w in wordDict:
                #w == s[i-len(w)+1:i+1] checks if word starting at i index is a fit
                #d[i-len(w)] checks if current the index prior to word starting is marked True
                #i-len(w) checks for first index -1
                if w == s[i-len(w)+1:i+1] and (d[i-len(w)] == True or i-len(w) == -1):
                    d[i] = True
        #result stored in last index
        return d[-1]