#This implementation allows duplicates, so if given coins [1], 1 will be allowed to be used multiple times
def totalCoinChangeWays(coins, target):
	dp = [0 for x in range(target+1)] for y in range(len(coins)+1)]
	
	k = 0
	while k < len(coins)+1:
		dp[k][0] = 1
		k+=1

	for i in range(1,len(coins)+1):
		for j in range(1,len(target)+1):
			if j >= coins[i]:
				dp[i][j] = 1 + dp[i-coins[i]][j]
				
	return dp[i][j]