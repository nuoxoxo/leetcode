class Solution:
    def rangeSumBST(self, node: Optional[TreeNode], lo: int, hi: int) -> int:
        if not node or lo > hi:
            return 0
        if node.val < lo:
            return self.rangeSumBST(node.right, lo, hi)
        if node.val > hi:
            return self.rangeSumBST(node.left, lo, hi)
        r = node.val + self.rangeSumBST(node.right, lo, hi) + self.rangeSumBST(node.left, lo, hi)
        return r

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
