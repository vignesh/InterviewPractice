#No duplicate combinations, therefore every number in array can only be used once
class Solution(object):
    def combinationSum2(self, candidates, target):
        """
        :type candidates: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        start = 0
        path  = []
        result = []
        candidates.sort()
        print self.combinationSum2Helper(candidates, target, path, result, start)
        
    def combinationSum2Helper(self, numbers, target, path, result, start):
        #base case
        if target == 0:
            result.append(path)
            return 
        
        for i in range(start, len(numbers)):
            #avoid duplicates
            if i < start and numbers[i] == numbers[i-1]:
                continue
            #no need to continue target
            if numbers[i] > target:
                break
            #decrease target, update path, increment start index
            self.combinationSum2Helper(numbers, target-numbers[i], path+[numbers[i]], result, i+1)
        print result
        return result
        
            