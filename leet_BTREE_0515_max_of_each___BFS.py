# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def largestValues(self, root: Optional[TreeNode]) -> List[int]:
        if not root:
            return []
        D = [root]
        res = []
        while D:
            res.append(max(n.val for n in D))
            temp = []
            for d in D:
                if d.left:
                    temp.append(d.left)
                if d.right:
                    temp.append(d.right)
            D = temp
        return res

