# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxLevelSum(self, root: Optional[TreeNode]) -> int:
        if not root:
            return 0
        dq = [root]
        record = -1e9
        level = 0
        res = 0
        while dq:
            level += 1
            curr = 0
            size = len(dq)
            for i in range(size):
                node = dq.pop(0)
                curr += node.val
                if node.left:
                    dq.append(node.left)
                if node.right:
                    dq.append(node.right)
            if curr > record:
                res = level
            record = max(curr, record)
        return res

