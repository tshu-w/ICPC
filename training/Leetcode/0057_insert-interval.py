class Solution:
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        ans = []

        i, n = 0, len(intervals)
        while (i < n):
            if (intervals[i][0] <= newInterval[0] <= intervals[i][1]):
                j = i + 1
                while (j < n and newInterval[1] > intervals[j + 1][1]):
                    j += 1
                ans.append([intervals[i][0], max(intervals[j][1], newInterval[i][1])])
            else:
                ans.append(intervals[i])

        return ans
