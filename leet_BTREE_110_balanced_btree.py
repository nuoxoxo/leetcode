# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        if root is None:
            return True

        def count_depth(node: TreeNode) -> int:
            if node is None:
                return 0
            L, R = count_depth(node.left), count_depth(node.right)
            if L < 0 or R < 0:
                return -1
            if abs(L - R) > 1:
                return -1
            return 1 + max(L, R)
        
        return count_depth(root) > 0
