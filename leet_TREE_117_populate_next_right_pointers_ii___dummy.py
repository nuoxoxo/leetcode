"""
# Definition for a Node.
class Node:
    def __init__(self, val: int = 0, left: 'Node' = None, right: 'Node' = None, next: 'Node' = None):
        self.val = val
        self.left = left
        self.right = right
        self.next = next
"""

class Solution:
    def connect(self, node: 'Node') -> 'Node':
        if not node:
            return node
        cur = node
        while cur:
            dum = Node(0)
            tmp = dum
            while cur:
                if cur.left:
                    tmp.next = cur.left
                    tmp = tmp.next
                if cur.right:
                    tmp.next = cur.right
                    tmp = tmp.next
                cur = cur.next
            cur = dum.next
        return node
