# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def getTargetCopy(self, o: TreeNode, c: TreeNode, t: TreeNode) -> TreeNode:
        if not o:
            return o
        if o == t:
            return c
        node = self.getTargetCopy(o.left, c.left, t)
        if node:
            return node
        return self.getTargetCopy(o.right, c.right, t)
