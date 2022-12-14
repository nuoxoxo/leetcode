# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        here = root.val
        pv = p.val
        qv = q.val
        if here > pv and here > qv:
            return self.lowestCommonAncestor(root.left, p, q)
        if here < pv and here < qv:
            return self.lowestCommonAncestor(root.right, p, q)
        return root
