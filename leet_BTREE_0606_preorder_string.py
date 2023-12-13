# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def tree2str(self, root: Optional[TreeNode]) -> str:
        def preorder(node):
            if not node:
                return ''
            res = str(node.val)
            if node.left:
                res += '(' + preorder(node.left) + ')'
            if node.right:
                if not node.left:
                    res += '()'
                res += '(' + preorder(node.right) + ')'
            return res
        return preorder( root )
