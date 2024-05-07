# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def numComponents(self, head: Optional[ListNode], nums: List[int]) -> int:
        seen = set(nums)
        node = head
        cut = True
        res = 0
        while node:
            if node.val in seen:
                if cut:
                    res += 1
                cut = False
            else:
                cut = True
            node = node.next
        return res
