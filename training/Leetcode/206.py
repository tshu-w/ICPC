# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def reverseList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        lst = None
        while head:
            nxt = head.next
            head.next = lst
            lst, head = head, nxt
        return lst
