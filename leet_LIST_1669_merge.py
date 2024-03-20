# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeInBetween(self, list1: ListNode, a: int, b: int, list2: ListNode) -> ListNode:
        pA, pB, head = list1, list1, list1
        p2end = list2
        while a > 1 and pA:
            a -= 1
            b -= 1
            pA = pA.next
            pB = pB.next
        while b > -1 and pB:
            b -= 1
            pB = pB.next
        while p2end.next:
            p2end = p2end.next
        assert a == 1
        assert b == -1
        pA.next = list2
        p2end.next = pB
        return head
