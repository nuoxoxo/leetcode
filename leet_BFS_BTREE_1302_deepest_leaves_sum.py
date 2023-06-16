# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def deepestLeavesSum(self, root: Optional[TreeNode]) -> int:
        dq = [ root ]
        res = 0
        while dq:
            res = 0
            level = len(dq)
            for _ in range(level):
                node = dq.pop(0)
                res += node.val
                if node.left:
                    dq.append(node.left)
                if node.right:
                    dq.append(node.right)
        return res
