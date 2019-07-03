class Solution:
    def maxProfit(self, k, prices):
        """
        :type k: int
        :type prices: List[int]
        :rtype: int
        """
        if k >= len(prices) // 2:
            return sum(sell - buy for sell, buy in zip(prices[1:], prices[:-1]) if sell - buy > 0)
        mi = [float('-inf')] * (k + 1)
        ans = [0] * (k + 1)
        for price in prices:
            for i in range(1, k + 1):
                mi[i] = max(mi[i], ans[i - 1] - price)
                ans[i] = max(ans[i], mi[i] + price)
        return ans[k]
