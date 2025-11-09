class Solution:
    def minSwaps(self, grid: List[List[int]]) -> int:
        n = len(grid)
        nums = []

        for i in range(n):
            for j in range(n - 1, -1, -1):
                if (grid[i][j] != 0):
                    nums.append(j)
                    break
            else:
                nums.append(0)

        count = 0
        for i in range(n):
            for j in range(i, n):
                if (nums[j] <= i):
                    for k in range(j, i, -1):
                        nums[k], nums[k - 1] = nums[k - 1], nums[k]
                        count += 1
                    break

        for i in range(n):
            if (nums[i] > i):
                return -1
        else:
            return count
