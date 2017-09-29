class Solution(object):
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        
        stack = []
        openings = ['[', '{', '(']
        
        for char in s:
            if char in openings:
                stack.append(char)
            if char == "}":
                if len(stack) == 0 or stack.pop() != "{":
                    return False
            if char == "]":
                if len(stack) == 0 or stack.pop() != "[":
                    return False
            if char == ")":
                if len(stack) == 0 or stack.pop() != "(":
                    return False
                
        if len(stack) != 0:
            return False
        
        return True
        