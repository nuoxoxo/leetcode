# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def minDepth(self, r: Optional[TreeNode]) -> int:
        if r is None:
            return 0
        if r.left is None:
            return 1 + self.minDepth(r.right)
        if r.right is None:
            return 1 + self.minDepth(r.left)
        return 1 + min( self.minDepth(r.left), self.minDepth(r.right) )
