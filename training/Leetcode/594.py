class Solution:
    def findLHS(self, nums: List[int]) -> int:
        dic = {}
        for num in nums:
            dic[num] = dic.get(num, 0) + 1

        ans = 0
        for key, value in dic.items():
            if key + 1 in dic:
                ans = max(ans, dic[key + 1] + value)

        return ans
