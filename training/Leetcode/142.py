# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def detectCycle(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        fast = slow = head
        while fast and slow:
            try:
                slow, fast = slow.next, fast.next.next
            except:
                return None
            if fast == slow:
                fast = head
                while fast != slow:
                    slow, fast = slow.next, fast.next
                return slow
        return None
