# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def swapNodes(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        lend = head
        rend = head
        p = head
        while k > 1:
            lend = lend.next
            p = p.next
            k -= 1
        while p.next:
            rend = rend.next
            p = p.next
        n = lend.val
        lend.val = rend.val
        rend.val = n
        return head
