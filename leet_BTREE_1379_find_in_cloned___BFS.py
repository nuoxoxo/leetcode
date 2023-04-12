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
        qo = []
        qc = []
        qo.append(o)
        qc.append(c)
        while len(qo) != 0:
            o, c = qo.pop(0), qc.pop(0)
            if o == t:
                return c
            if o.left:
                qo.append(o.left)
            if o.right:
                qo.append(o.right)
            if c.left:
                qc.append(c.left)
            if c.right:
                qc.append(c.right)
        return None
