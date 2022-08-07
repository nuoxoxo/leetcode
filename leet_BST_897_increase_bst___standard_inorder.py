# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    dum = TreeNode()
    end = dum
    def increasingBST(self, root: TreeNode) -> TreeNode:
        dum = TreeNode()
        self.end = dum
        def inorder_traversal(node):
            if node:
                inorder_traversal(node.left)
                self.end.right = node
                self.end = node
                self.end.left = None
                inorder_traversal(node.right)
        inorder_traversal(root)
        return dum.right
