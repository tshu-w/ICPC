# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def sortedListToBST(self, head):
        """
        :type head: ListNode
        :rtype: TreeNode
        """
        def convert(head, n):
            if n == 0:
                return None
            mid = head
            for i in range(n // 2):
                mid = mid.next
            root = TreeNode(mid.val)
            root.left = convert(head, n // 2)
            root.right = convert(mid.next, n - n // 2 - 1)
            return root

        n, ptr = 0, head
        while ptr:
            n += 1
            ptr = ptr.next
        return convert(head, n)
