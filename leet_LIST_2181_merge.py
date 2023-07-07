# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def mergeNodes(self, head: Optional[ListNode]) -> Optional[ListNode]:
        slow = head
        fast = head.next
        temp = 0
        while fast:
            if fast.val != 0:
                temp += fast.val
            else:
                slow = slow.next
                slow.val = temp
                temp = 0
            fast = fast.next
        slow.next = None
        return head.next
        # Beginning of the linked list have Node.val == 0
