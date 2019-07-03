class Solution:
    def findDuplicate(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        # while (nums[0] != nums[nums[0]]):
        #     # swap(nums[0], nums[nums[0]])
        #     tmp = nums[0]
        #     nums[0] = nums[nums[0]]
        #     nums[tmp] = tmp
        # return nums[0]
        slow, fast = nums[0], nums[nums[0]]
        while slow != fast:
            slow, fast = nums[slow], nums[nums[fast]]
        fast = 0
        while slow != fast:
            slow, fast = nums[slow], nums[fast]
        return slow
