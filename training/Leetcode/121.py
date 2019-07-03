class Solution:
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        mi, ans =  float('inf'), 0
        for price in prices:
            ans = max(ans, price - mi)
            mi = min(price, mi)
        return ans
