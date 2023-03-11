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
        for n in node.children:
            res = max(self.maxDepth(n), res)
        return res + 1
