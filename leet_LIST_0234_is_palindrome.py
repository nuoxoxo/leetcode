# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def isPalindrome(self, head: Optional[ListNode]) -> bool:
        return [
            self.Reverse_linked_list,
            self.Get_to_the_middle,
        ][0](head)

    def Reverse_linked_list(self, head: Optional[ListNode]) -> bool:
        f,s = head, head
        rev = None#head#ListNode(head.val)
        while f and f.next:
            f = f.next.next
            nxt = s.next # preserve the Next-ptr
            s.next = rev # reverse this node by re-assigning its Next-pointer
            rev = s # move rightwards
            s = nxt # move rightwards
        if f:
            s = s.next
        while rev and s:
            if rev.val != s.val:
                return False
            s = s.next
            rev = rev.next
        return True

    def Get_to_the_middle(self, head: Optional[ListNode]) -> bool:
        f,s = head, head
        half = []
        while f and f.next:
            f = f.next.next
            half.append(s.val)
            s = s.next
        if f:
            s = s.next
        while s:
            if not half or s.val != half.pop():
                return False
            s = s.next
        return not half

