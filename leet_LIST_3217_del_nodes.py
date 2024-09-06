# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def modifiedList(self, nums: List[int], head: Optional[ListNode]) -> Optional[ListNode]:
        return [
            # NewList,
            InPlace,
        ][0](nums, head)

def InPlace(nums: List[int], head: Optional[ListNode]) -> Optional[ListNode]:
    seen = set(nums)
    dummy = ListNode(-1)
    dummy.next = head
    node = dummy#head
    while node:
        if node.next and node.next.val in seen:
            node.next = node.next.next
            continue
        node = node.next
    return dummy.next

def NewList(nums: List[int], head: Optional[ListNode]) -> Optional[ListNode]:
    seen = set(nums)
    node = head
    dummy = ListNode(-1)
    res = dummy
    while node:
        if node.val not in seen:
            dummy.next = ListNode(node.val)
            dummy = dummy.next
        node = node.next
    return res.next

