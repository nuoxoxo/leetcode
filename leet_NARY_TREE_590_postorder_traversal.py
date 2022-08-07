"""
# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children
"""

class Solution:
    def postorder(self, root: 'Node') -> List[int]:
        E = []
        self.helper(root, E)
        return E

    def helper(self, root: 'Node', v: List[int]):
        if root is None:
            return
        for i in root.children:
            self.helper(i, v)
        v.append(root.val)
