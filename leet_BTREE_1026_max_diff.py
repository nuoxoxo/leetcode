class Solution:
    def maxAncestorDiff(self, root: Optional[TreeNode]) -> int:
        def solve(node: TreeNode, Mx: int, Mn: int) -> int:
            if not node:
                return Mx - Mn
            Mx = max(Mx, node.val)
            Mn = min(Mn, node.val)
            L = solve(node.left, Mx, Mn)
            R = solve(node.right, Mx, Mn)
            return max(L, R)
        if not root:
            return 0
        return solve(root, root.val, root.val)

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

