from functools import reduce
class Solution:
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        a = b = reduce(lambda x, y : x ^ y, nums)
        for i in range(a.bit_length()):
            if a >> i & 1:
                for num in nums:
                    if num >> i & 1:
                        a ^= num
                break
        return [a, b ^ a]
