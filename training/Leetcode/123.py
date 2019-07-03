class Solution:
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        mi1 = mi2 = float('-inf')
        ans1 = ans2 = 0
        for price in prices:
            mi1 = max(mi1, -price)
            ans1 = max(ans1, price + mi1)
            mi2 = max(mi2, ans1 - price)
            ans2 = max(ans2, price + mi2)
        return ans2
