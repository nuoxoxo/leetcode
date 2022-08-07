# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head:
            return None
        before = None
        after = None
        ego = head
        while ego:
            after = ego.next
            ego.next = before
            before = ego
            ego = after
        return before
