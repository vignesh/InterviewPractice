#O(m*n space and time)

def longestCommonSubstring(string1, string2):
	result = 0
	dp = [[0 for x in range(len(string2)+1)] for y in range(len(string1)+1)]
	for i in range(len(string1)+1):
		for j in range(len(string2)+1):
			if i == 0 or j == 0:
				dp[i][j] == 0
			elif string1[i-1] == string2[j-1]:
				dp[i][j] = dp[i-1][j-1] + 1
				result =  max(result, dp[i][j])
			else:
				dp[i][j] = 0
	return result

def main():
	string1 = "abcdaf"
	string2 = "zbcdf"
	print longestCommonSubstring(string1, string2)

if __name__ == "__main__":
    main()