class Solution(object):
    def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        # nums.sort()
        # return nums[len(nums) // 2]
        num, cnt = 0, 0
        for i in nums:
            if cnt == 0:
                num, cnt = i, 1
            else:
                cnt += 1 if num == i else -1
        return num
