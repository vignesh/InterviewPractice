def atoi(string):
	if len(string) == 0:
		return 0;

	sign = 1
	result = 0
	if string[0] == '-':
		sign = -1

	for char in string[1:]:
		if checkNumber(char) == False:
			return False

		#Example - In Ascii '0' is a character with value 0x30 and '9' is 0x39 thereforem subtracting converts to digit valye
		result = result * 10 + (char - '0')

	finalResult = sign * result

	if finalResult > sys.maxint:
		return sys.maxint

	if finalResult < sys.minint:
		return sys.minint

	return finalResult


def checkNumber(char):
	if (char >='0' and char <='9'):
		return True
	return False





