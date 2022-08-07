class Solution:
    def rightSideView(self, node: Optional[TreeNode]) -> List[int]:
        res = []
        if not node:
            return res
        dq = [node]
        while dq:
            size = len(dq)
            i = 1
            while i < size + 1:
                n = dq.pop(0)
                if i == size:
                    res.append(n.val)
                if n.left:
                    dq.append(n.left)
                if n.right:
                    dq.append(n.right)
                i += 1
        return res


# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
