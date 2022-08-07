# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def getTargetCopy(self, o: TreeNode, c: TreeNode, t: TreeNode) -> TreeNode:
        if not o:
            return None
        if o == t:
            return c
        dq = []
        dq.append(c)
        while len(dq) != 0:
            c = dq.pop(0)
            if c.val == t.val:
                return c
            if c.left:
                dq.append(c.left)
            if c.right:
                dq.append(c.right)
        return None
