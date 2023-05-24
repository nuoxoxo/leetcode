# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def addTwoNumbers(self, t1: Optional[ListNode], t2: Optional[ListNode]) -> Optional[ListNode]:
        dumm = ListNode()
        curr = dumm
        carry = 0
        while t1 or t2 or carry != 0:
            if t1:
                carry += t1.val
                t1 = t1.next
            if t2:
                carry += t2.val
                t2 = t2.next
            temp = ListNode(carry % 10)
            curr.next = temp
            curr = curr.next
            carry //= 10
        return dumm.next
