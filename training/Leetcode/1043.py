import heapq


class Solution:
    def maxSumAfterPartitioning(self, A: List[int], K: int) -> int:
        n = len(A)
        dp = [0] * n

        for i in range(n):
            curMax = A[i]
            for k in range(0, min(K, i + 1)):
                curMax = max(curMax, A[i - k])
                dp[i] = max(dp[i], (dp[i - k - 1] if i - k - 1 >= 0 else 0) + curMax * (k + 1))

        return dp[n - 1]
