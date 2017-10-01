class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        total = 0
        for price in range(len(prices)-1):
            if prices[price + 1] > prices[price]:
                total += prices[price+1] - prices[price]
        return total