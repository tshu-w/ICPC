# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def sortedArrayToBST(self, nums):
        """
        :type nums: List[int]
        :rtype: TreeNode
        """
        def convert(l, r):
            if l == r:
                return None
            mid = (l + r) // 2
            root = TreeNode(nums[mid])
            root.left = convert(l, mid)
            root.right = convert(mid + 1, r)
            return root
        return convert(0, len(nums))
