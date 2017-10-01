class Solution(object):
    def romanToInt(self, s):
        """
        :type s: str
        :rtype: int
        """
        romanMap = {'M': 1000,'D': 500 ,'C': 100,'L': 50,'X': 10,'V': 5,'I': 1}
        convertedNumber = 0
        for i in range(len(s)-1):
            if romanMap[s[i]] < romanMap[s[i+1]]:
                convertedNumber -= romanMap[s[i]]
            else:
                convertedNumber += romanMap[s[i]]
        return convertedNumber + romanMap[s[-1]]
        