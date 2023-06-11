# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def rotateRight(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        if not head:
            return head
        tail = head
        n = 1
        while tail.next:
            tail = tail.next
            n += 1
        pivot = head
        k %= n
        if k == 0:
            return head
        i = 0
        while i < n - k - 1:
            pivot = pivot.next
            i += 1
        res = pivot.next
        pivot.next = None
        tail.next = head
        return res
