class Solution:
    def isSymmetric(self, node: Optional[TreeNode]) -> bool:
        if node is None:
            return True
        return self.isSame(node.left, node.right)

    def isSame(self, L, R):
        if L is None and R is None:
            return True
        if L is None or R is None:
            return False
        return L.val == R.val and self.isSame(L.left, R.right) and self.isSame(L.right, R.left)
    
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
