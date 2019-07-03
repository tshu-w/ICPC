class Solution:
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        hold = float('-inf')
        crash = prash = 0
        for price in prices:
            hold = max(hold, prash - price)
            prash = crash
            crash = max(crash, price + hold)
        return crash
