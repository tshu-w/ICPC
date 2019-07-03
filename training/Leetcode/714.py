class Solution:
    def maxProfit(self, prices, fee):
        """
        :type prices: List[int]
        :type fee: int
        :rtype: int
        """
        hold, crash = float('-inf'), 0
        for price in prices:
            hold = max(hold, crash-price)
            crash = max(crash, hold + price - fee)
        return crash
