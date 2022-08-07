"""
# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children
"""

class Solution:
    def maxDepth(self, node: 'Node') -> int:
        if not node:
            return 0
        res = 0
        dq = []
        dq.append(node)
        while (len(dq) != 0):
            n = len(dq)
            while n != 0:
                p = dq.pop(0)
                for c in p.children:
                    if c:
                        dq.append(c)
                n -= 1
            res += 1
        return res
