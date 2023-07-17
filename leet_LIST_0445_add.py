# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def addTwoNumbers(self, a: Optional[ListNode], b: Optional[ListNode]) -> Optional[ListNode]:
        s1 = []
        s2 = []
        while a:
            s1.append(a.val)
            a = a.next
        while b:
            s2.append(b.val)
            b = b.next
        head = None
        carry = 0
        while carry != 0 or s1 or s2:
            node = ListNode(0)
            n1 = 0 if not s1 else s1.pop()
            n2 = 0 if not s2 else s2.pop()
            temp = n1 + n2 + carry
            carry = temp // 10
            node.val = temp % 10
            node.next = head
            head = node
        return head
