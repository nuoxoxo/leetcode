# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def minDiffInBST(self, root: Optional[TreeNode]) -> int:
        D = [root]
        n = []
        while D:
            node = D.pop(0)
            n.append(node.val)
            if node.left:
                D.append(node.left)
            if node.right:
                D.append(node.right)
        n.sort()
        res = 1e9
        for i in range(1, len(n)):
            tmp = n[i] - n[i - 1]
            res = min(res, tmp)
        return res

