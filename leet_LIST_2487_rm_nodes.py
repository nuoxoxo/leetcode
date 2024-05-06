# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeNodes(self, head: Optional[ListNode]) -> Optional[ListNode]:
        return [
            # popping_monostack,
            reverse_reverse, # fast
        ][0](head)

def popping_monostack(head: Optional[ListNode]) -> Optional[ListNode]:
    dummy = ListNode(10 ** 20)
    D = [dummy]
    node = head
    while node:
        while D[-1].val < node.val:
            D.pop()
        D[-1].next = node
        D.append(node)
        node = node.next
    return dummy.next

def reverse_reverse(head: Optional[ListNode]) -> Optional[ListNode]:
    def reverse_llist(head):
        assert head
        curr = head
        _next, _prev = None, None
        while curr:
            _next = curr.next
            curr.next = _prev
            _prev = curr
            curr = _next
        return _prev
    _new = reverse_llist(head)
    node = _new
    while node.next:
        if node.val > node.next.val:
            node.next = node.next.next
        else:
            node = node.next
    return reverse_llist(_new)
