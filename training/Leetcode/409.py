class Solution:
    def longestPalindrome(self, s: str) -> int:
        cnt = {}
        for ch in s:
            cnt[ch] = cnt.get(ch, 0) + 1

        ans, flag = 0, True
        for val in cnt.values():
            ans += val // 2 * 2
            if flag and val % 2:
                ans += 1
                flag = False

        return ans
