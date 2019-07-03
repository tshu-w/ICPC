class Solution:
    def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        num1, num2 = 0, 0
        cnt1, cnt2 = 0, 0
        for num in nums:
            if num1 == num:
                cnt1 += 1
                continue
            if num2 == num:
                cnt2 += 1
                continue
            if cnt1 == 0:
                num1, cnt1 = num, 1
                continue
            if cnt2 == 0:
                num2, cnt2 = num, 1
                continue
            cnt1 -= 1
            cnt2 -= 1
        return ([num1] if nums.count(num1) > len(nums) // 3 and cnt1 else []) \
            + ([num2] if nums.count(num2) > len(nums) // 3 and cnt2 else [])
