# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None
from Queue import PriorityQueue
class Solution(object):
    def mergeKLists(self, lists):
        """
        :type lists: List[ListNode]
        :rtype: ListNode
        """
        head = cur = ListNode(0)
        que = PriorityQueue()
        for node in lists:
            if node:
                que.put((node.val, node))
        while not que.empty():
            val, node = que.get()
            cur.next = ListNode(val)
            cur = cur.next
            node = node.next
            if node:
                que.put((node.val, node))
        return head.next
