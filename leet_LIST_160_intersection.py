# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def getIntersectionNode(self, A: ListNode, B: ListNode) -> Optional[ListNode]:
        a, b = A, B
        while a != b:
            a = B if not a else a.next
            b = A if not b else b.next
        return a
