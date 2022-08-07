# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def lowestCommonAncestor(self, node: 'TreeNode', L: 'TreeNode', R: 'TreeNode') -> 'TreeNode':
        if node.val > L.val and node.val > R.val:
            return self.lowestCommonAncestor(node.left, L, R)
        if node.val < L.val and node.val < R.val:
            return self.lowestCommonAncestor(node.right, L, R)
        return node

    
