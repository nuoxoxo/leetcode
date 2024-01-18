# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reorderList(self, head: Optional[ListNode]) -> None:
        return [
            self.Solution_2pass,
        ][ random.randint(0,0) ]( head )

    def Solution_2pass(self, head: Optional[ListNode]) -> None:
        print('/Solution_2pass - 95% fast enough')
        if not head or not head.next or not head.next.next:
            return 
        dq = []
        sizeof = 0
        node = head
        while node:
            dq.append( node )
            sizeof += 1
            node = node.next
        node = head
        for _ in range( sizeof // 2 ):
            # prepare new node
            new_node = dq.pop()
            new_node.next = node.next
            # adjust pointer
            node.next = new_node
            node = node.next.next
        node.next = None
