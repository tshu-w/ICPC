class Solution(object):
    def maxArea(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        l, r, ans = 0, len(height) - 1, 0
        while l < r:
            ans = max(ans, min(height[r], height[l]) * (r - l))
            if height[l] < height[r]:
                l += 1
            else:
                r -= 1
        return ans
