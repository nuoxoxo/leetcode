# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def deleteMiddle(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head or not head.next:
            return None
        f = head
        s = head
        while f and f.next: # slow will stop exactly at the middle node
            p = s
            s = s.next
            f = f.next.next
        p.next = s.next 
        return head
