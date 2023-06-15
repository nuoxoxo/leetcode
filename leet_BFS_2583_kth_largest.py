# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def kthLargestLevelSum(self, root: Optional[TreeNode], k: int) -> int:
        dq = [root]
        res = []
        while dq:
            level = 0 # level sum
            for _ in  range(len(dq)):
                node = dq.pop(0)
                level += node.val
                if node.left:
                    dq.append(node.left)
                if node.right:
                    dq.append(node.right)
            res.append(level)
        if len(res) < k:
            return -1
        return sorted(res, reverse=True)[k - 1]
        return sorted(res)[-k] # idem
