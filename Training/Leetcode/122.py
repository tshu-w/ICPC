class Solution:
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        lst, ans = -1, 0
        for price in prices:
            if lst != -1 and lst < price:
                ans += price - lst
            lst = price
        return ans
