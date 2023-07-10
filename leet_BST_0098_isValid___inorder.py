
class Solution:
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        def inorder(self, node, n) -> None:
            if not node:
                return
            inorder(self, node.left, n)
            n.append(node.val)
            inorder(self, node.right, n)
        n = []
        inorder(self, root, n)
        for i in range(1, len(n)):
            if n[i - 1] >= n[i]:
                return False
        return True

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
