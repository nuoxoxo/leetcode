# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def rangeSumBST(self, root: Optional[TreeNode], low: int, high: int) -> int:
        if not root:
            return 0
        n = root.val
        if n <= high and n >= low:
            return n + \
                self.rangeSumBST(root.left, low, high) + \
                self.rangeSumBST(root.right, low, high)
        return self.rangeSumBST(root.left, low, high) + \
            self.rangeSumBST(root.right, low, high)
