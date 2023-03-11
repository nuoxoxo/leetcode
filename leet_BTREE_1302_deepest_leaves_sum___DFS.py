# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def deepestLeavesSum(self, root: Optional[TreeNode]) -> int:
        self.res = 0
        self.D = 0
        def dfs(node, L):
            if not node:
                return
            if L == self.D:
                self.res += node.val
            elif L > self.D:
                self.res = node.val
                self.D = L
            dfs(node.right, L + 1)
            dfs(node.left, L + 1)
        dfs(root, 0)
        return self.res
