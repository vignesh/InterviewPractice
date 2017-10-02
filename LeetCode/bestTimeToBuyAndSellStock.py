import sys
class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        profit = 0
        minPrice = sys.maxsize
        for i in range(len(prices)):
            minPrice = min(minPrice, prices[i])
            profit = max(profit, prices[i]-minPrice)
        return profit
        