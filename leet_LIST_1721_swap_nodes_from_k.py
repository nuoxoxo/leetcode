# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next


# solved again in 2023

class Solution:
    def swapNodes(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        p = head

        while p and k > 1:
            p = p.next
            # i += 1
            k -= 1
        from_left = p
        from_right = head
        while p.next:
            from_right = from_right.next
            p = p.next
        from_left.val, from_right.val = from_right.val, from_left.val
        return head

"""
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
"""
