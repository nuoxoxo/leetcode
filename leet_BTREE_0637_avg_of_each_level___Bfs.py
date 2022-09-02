# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def averageOfLevels(self, root: Optional[TreeNode]) -> List[float]:
        dq, r = [root], []
        while dq:
            temp = 0
            size = len(dq)
            for _ in range(size):
                p = dq.pop(0)
                temp += p.val
                if p.left:
                    dq.append(p.left)
                if p.right:
                    dq.append(p.right)
            r.append(temp / size)
        return r
