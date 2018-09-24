# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def reverseBetween(self, head, m, n):
        """
        :type head: ListNode
        :type m: int
        :type n: int
        :rtype: ListNode
        """
        p = ListNode(0)
        p.next = head
        for i in range(m - 1):
            p = p.next
        q = p.next
        for i in range(n - m):
            t = q.next
            q.next = q.next.next
            t.next = p.next
            p.next = t
        if m == 1:
            return p.next
        else:
            return head
