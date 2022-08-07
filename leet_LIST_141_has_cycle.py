# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        if not head:
            return False
        h, t = head, head
        while h.next and h.next.next:
            h = h.next.next
            t = t.next
            if h is t:
                return True
        return False
