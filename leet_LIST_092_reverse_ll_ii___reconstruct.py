# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseBetween(self, head: Optional[ListNode], left: int, right: int) -> Optional[ListNode]:
        e = []
        p = head
        while p:
            e.append(p.val)
            p = p.next
        # reverse a portion of a list
        e[left - 1 : right] = e[left - 1 : right][::-1]
        dummy = ListNode(0)
        p = dummy
        for n in e:
            temp = ListNode(n)
            p.next = temp
            p = p.next
        return dummy.next
        
