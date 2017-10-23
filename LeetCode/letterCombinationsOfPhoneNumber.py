class Solution(object):
    def letterCombinations(self, digits):
        """
        :type digits: str
        :rtype: List[str]
        """
        mapping = {'0':'', '1':'', '2': 'abc', '3': 'def', '4': 'ghi', '5': 'jkl', '6': 'mno', '7': 'pqrs', '8': 'tuv', '9': 'wxyz'}
        results = [""]
        if len(digits) == 0:
            return []
        for digit in digits:
            updatedResults = []
            #possible letters for given digit
            letters = list(mapping[digit])
            #for every le
            for letter in letters:
                #for every string in results in array
                for string in results:
                    #add every combination of previous strings with new letters
                    updatedResults.append(string+letter)
            #update results array
            results = updatedResults
        return results

#Implementation with a queue, no need to keep copying reuslts array
from Queue import *
class Solution(object):
    def letterCombinations(self, digits):
        """
        :type digits: str
        :rtype: List[str]
        """            
        mapping = {'0':'', '1':'', '2': 'abc', '3': 'def', '4': 'ghi', '5': 'jkl', '6': 'mno', '7': 'pqrs', '8': 'tuv', '9': 'wxyz'}
        results = Queue()
        results.put("")
        if len(digits) == 0:
            return []
        for i, digit in enumerate(digits):
            letters = list(mapping[digit])
            while results.qsize() == i:
                string = results.get()
                for letter in letters:
                    results.put(string+letter)
        return results