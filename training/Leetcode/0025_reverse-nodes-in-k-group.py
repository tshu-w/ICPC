# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseKGroup(self, head: ListNode, k: int) -> ListNode:
        pre = None
        left = head

        while (left is not None):
            right = left

            for i in range(k - 1):
                if right.next is None:
                    return head
                else:
                    right = right.next

            right_next = right.next

            cur, nxt = left, left.next
            while (cur != right):
                nnxt = nxt.next
                nxt.next = cur
                cur = nxt
                nxt = nnxt

            left.next = right_next

            if pre is None:
                head = right
            else:
                pre.next = right

            pre = left
            left = left.next

        return head
