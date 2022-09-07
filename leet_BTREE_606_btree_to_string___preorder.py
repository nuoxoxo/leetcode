# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def tree2str(self, root: Optional[TreeNode]) -> str:
        a = []
        def preorder(node):
            if not node:
                return
            a.append('(')
            a.append(str(node.val))
            if not node.left and node.right:
                a.append('()')
            preorder(node.left)
            preorder(node.right)
            a.append(')')
        preorder(root)
        return ''.join(a[1:-1])
