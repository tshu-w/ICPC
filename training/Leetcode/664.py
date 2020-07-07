import re


class Solution:
    def strangePrinter(self, s: str) -> int:
        s = re.sub(r"(.)\1+", r"\1", s)
        n = len(s)

        if not s:
            return 0

        dp = [[0] * n for _ in range(n)]
        for r in range(n):
            for l in range(r, -1, -1):
                if l == r:
                    dp[l][r] = 1
                else:
                    dp[l][r] = 1 + dp[l + 1][r]
                    if s[l] == s[r]:
                        dp[l][r] = min(dp[l][r], dp[l][r - 1])
                    for m in range(l + 1, r):
                        if s[m] == s[l]:
                            dp[l][r] = min(dp[l][r], dp[l][m - 1] + dp[m + 1][r])

        return dp[0][-1]
