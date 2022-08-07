# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right


class Solution:
    def convertBST(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        def reverse_inorder_traversal(node, total):
            if node:
                reverse_inorder_traversal(node.right, self.total)
                self.total += node.val
                node.val = self.total
                reverse_inorder_traversal(node.left, self.total)
            return node
        self.total = 0
        return reverse_inorder_traversal(root, self.total)
