class Solution(object):
    def fizzBuzz(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        finalArray = []
        number = 1
        while number <= n:
            if number % 3 == 0 and number % 5 == 0:
                finalArray.append("FizzBuzz")
                number+=1
            elif number % 3 == 0:
                finalArray.append("Fizz")
                number+=1
            elif number % 5 == 0:
                finalArray.append("Buzz")
                number+=1
            else:
                finalArray.append(str(number))
                number+=1
        return finalArray
        