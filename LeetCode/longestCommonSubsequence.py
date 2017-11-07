def longestCommonSubsequence(string1, string2):
	m = len(string1)
	n = len(string2)
	dp = [[0 for x in range(n+1)] for y in range(m+1)]
	for i in range(m+1):
		for j in range(n+1):
			if i == 0 or j == 0:
				dp[i][j] = 0
			elif string1[i-1] == string2[j-1]:
				dp[i][j] = dp[i-1][j-1] + 1
			else:
				dp[i][j] = max(dp[i-1][j], dp[i][j-1])
	return dp[m][n]

def main():
	string1 = "abcdaf"
	string2 = "zbcdf"
	print longestCommonSubsequence(string1, string2)
	string1 = "AGGTAB"
	string2 = "GXTXAYB"
	print longestCommonSubsequence(string1, string2)

if __name__ == "__main__":
    main()