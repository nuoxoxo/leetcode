# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def isPalindrome(self, head: Optional[ListNode]) -> bool:
        d = []
        p = head
        while p:
            d.append(p.val)
            p = p.next
        p = head
        while p:
            if p.val != d.pop():
                return False
            p = p.next
        return True
