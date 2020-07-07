from collections import defaultdict

class Solution:
    def findRotateSteps(self, ring: str, key: str) -> int:
        index = defaultdict(list)
        for i, c in enumerate(ring):
            index[c].append(i)

        n, dp = len(ring), [0] * len(ring)
        for i, c in enumerate(key):
            for j in index[c]:
                if i == 0:
                    dp[j] = min(j, n - j) + 1
                else:
                    dp[j] = min(dp[k] + min(abs(j - k), n - abs(j - k)) for k in index[pre]) + 1
            pre = c

        return min(dp[i] for i in index[key[-1]])
