class Solution(object):
    def evalRPN(self, tokens):
        """
        :type tokens: List[str]
        :rtype: int
        """
        stack = []
        operators =  {
            "+": lambda x, y: float(y) + float(x),
            "-": lambda x, y: float(y) - float(x),
            "*": lambda x, y: float(y) * float(x),
            "/": lambda x, y: float(y) / float(x)}
        for token in tokens:
            if token in operators:
                if len(stack) >= 2:
                    num = stack.pop()
                    num2 = stack.pop()
                    #cannot divide by zero
                    if (token == '/') and (num == 0):
                        return 0
                    print num
                    print num2
                    result = operators[token](num, num2)
                    print result
                    print "----"
                    stack.append(int(result))
                #not enough numbers in stack for operation
                else:
                    return 0
            else:
                stack.append(int(token))
        
        #check if remaining numbers in stack, then invalid
        if len(stack) != 1:
            return 0
        return stack[0]           
