class Solution(object):
    def isAnagram(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        anagramMap = {}
        for char in s:
            if char not in anagramMap:
                anagramMap[char] = 1
            else:
                anagramMap[char] += 1
                
        for letter in t:
            if letter not in anagramMap:
                return False
            else:
                anagramMap[letter] -= 1
                if anagramMap[letter] == 0:
                    anagramMap.pop(letter, None)
        
        if bool(anagramMap) == True:
                return False
        else:
            return True