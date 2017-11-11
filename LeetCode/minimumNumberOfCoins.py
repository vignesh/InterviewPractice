def minimumNumberOfCoins(coins, target):
	dp = 0 for x in range(target+1)
	dp[0] = 0
	k = 1
	while k < len(dp):
		dp[k] = INT_MAX
		
	for i in range(len(coins)):
		for j in range(target):
			j >= coin[i]:
				dp[j] = min(dp[j], 1+ dp[j-coin[i]])
	return dp[j]
