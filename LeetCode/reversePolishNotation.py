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

#solution that inlcudes parentheses (NOT CORRECT), check link
#http://www.geeksforgeeks.org/expression-evaluation/
#proper solution is simialr but use two stacks one of for operators and one for values, and itearte until operator stack is empty
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
                    result = operators[token](num, num2)
                    stack.append(int(result))
                #not enough numbers in stack for operation
                else:
                    return 0
            elif token == "(":
                stack.push(token)
            elif token == ")":
                while stack[-1] != "(":
                    #not enough elements on stack
                    if len(stack) > 2:
                        return False
                    operator = stack.pop()
                    #check if opertor
                    if opertor not in operators:
                        return False
                    #get values for opeator
                    num = stack.pop()
                    num2 = stack.pop()
                    result = operators[opertor](num, num2)
                    stack.append(int(result))
                #remove ( 
                stack.pop()
            else:
                stack.append(int(token))
        
        #check if remaining numbers in stack, then invalid
        if len(stack) != 1:
            return 0
        return stack[0]           
