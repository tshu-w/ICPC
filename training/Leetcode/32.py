class Solution:
    def longestValidParentheses(self, s: str) -> int:
        ans, stack = 0, [(")", -1)]
        for i, x in enumerate(s):
            if stack[-1][0] == "(" and x == ")":
                stack.pop()
                ans = max(ans, i - stack[-1][1])
            else:
                stack.append((x, i))

        return ans
