class Solution:
    def trap(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        l, r = 0, len(height) - 1
        lmax = rmax = 0
        ans = 0
        while l < r:
            if height[l] < height[r]:
                if lmax > height[l]:
                    ans += lmax - height[l]
                else:
                    lmax = height[l]
                l += 1
            else:
                if rmax > height[r]:
                    ans += rmax - height[r]
                else:
                    rmax = height[r]
                r -= 1
        return ans
