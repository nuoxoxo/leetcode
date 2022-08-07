# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def reverseBetween(self, head: Optional[ListNode], left: int, right: int) -> Optional[ListNode]:
        if not head:
            return head
        ego = head
        left_end = None
        i = 1
        while i < left:
            left_end = ego
            ego = ego.next
            i += 1
        mid_head = None
        mid_end = ego
        after = None
        while ego:
            if i > right:
                break 
            after = ego.next
            ego.next = mid_head
            mid_head = ego
            ego = after
            i += 1
        if left_end:
            left_end.next = mid_head
        else:
            head = mid_head
        mid_end.next = ego
        return head
