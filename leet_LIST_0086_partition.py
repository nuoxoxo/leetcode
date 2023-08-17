# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def partition(self, head: Optional[ListNode], x: int) -> Optional[ListNode]:
        if not head:
            return head
        p = head
        L, R = [], []
        while p:
            n = p.val
            if n < x:
                L.append(n)
            else:
                R.append(n)
            p = p.next
        p = head
        for n in L:
            p.val = n
            p = p.next
        for n in R:
            p.val = n
            p = p.next
        return head
