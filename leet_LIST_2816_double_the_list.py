# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def doubleIt(self, head: Optional[ListNode]) -> Optional[ListNode]:
        num = 0
        node = head
        while node:
            num = num * 10 + node.val
            node = node.next
        num *= 2
        if num == 0:
            return ListNode(0)
        # make list
        node = ListNode()
        _head = node
        while num > 0:
            node.val = num % 10
            if num // 10 != 0:
                node.next = ListNode()
                node = node.next
            num //= 10
        # reverse
        _prev, _next = None, None
        node = _head
        while node:
            _next = node.next
            node.next = _prev
            _prev = node
            _head = _prev # track head
            node = _next
        return _head


