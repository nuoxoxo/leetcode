"""
# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children
"""

class Solution:
    def levelOrder(self, root: 'Node') -> List[List[int]]:
        r = []
        if not root:
            return r
        dq = deque()
        dq.append(root)
        while dq:
            temp = []
            size = len(dq)
            for _ in range(size):
                node = dq.popleft()
                for n in node.children:
                    dq.append(n)
                temp.append(node.val)
            r.append(temp)
        return r
