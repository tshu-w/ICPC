class Solution:
    def minFlips(self, target: str) -> int:
        cur = [0] * len(target)
        tgt = list(map(int, target))
        ans = 0
        for i in range(len(cur)):
            if (cur[i] + ans) % 2 != tgt[i]:
                ans += 1

        return ans
