class Solution:
    def rangeSumBST(self, root: Optional[TreeNode], low: int, high: int) -> int:
        if not root or low > high:
            return 0
        self.res = 0
        def recur(self, node: TreeNode, lo: int, hi: int) -> int:
            if not node:
                return
            if node.val <= hi and node.val >= lo:
                print(node.val)
                self.res += node.val
            recur(self, node.right, lo, hi)
            recur(self, node.left, lo, hi)
        recur(self, root, low, high)
        return self.res

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
