# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def swapPairs(self, head: ListNode) -> ListNode:
        pre = None
        left = head

        while (left is not None and left.next is not None):
            right = left.next

            left.next = right.next
            right.next = left

            if pre is None:
                head = right
            else:
                pre.next = right

            pre = left
            left = left.next

        return head
