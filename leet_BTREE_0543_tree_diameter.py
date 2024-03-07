# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        def dive(node, level) -> int:
            if not node:
                return 0
            L = dive(node.left, level)
            R = dive(node.right, level)
            nonlocal res
            res = max(res, L + R)
            return max(L, R) + 1
        res = 0
        dive(root, res)
        return res
