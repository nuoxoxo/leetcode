# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def findMode(self, root: Optional[TreeNode]) -> List[int]:
        if not root:
            return []
        res = []
        dq = [ root ]
        D = defaultdict(int)
        occ = 0
        while dq:
            node = dq.pop(0)
            D[node.val] += 1
            occ = max(occ, D[node.val])
            if node.left:
                dq.append(node.left)
            if node.right:
                dq.append(node.right)
        # for (key, val) in D.items():
        # both ways worked
        for key, val in D.items():
            if val == occ:
                res.append(key)
        return res
