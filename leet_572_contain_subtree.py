# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def isSubtree(self, root: Optional[TreeNode], sample: Optional[TreeNode]) -> bool:

        def isSame(r1: TreeNode, r2: TreeNode) -> bool:
            if r1 is None and r2 is None:
                return True
            if r1 is None or r2 is None:
                return False
            if r1.val != r2.val:
                return False
            return isSame(r1.left, r2.left) and isSame(r1.right, r2.right)

        if root is None and sample is None:
            return True
        if root is None or sample is None:
            return False
        if root.val == sample.val:
            if isSame(root, sample) is True:
                return True
        return self.isSubtree(root.left, sample) or self.isSubtree(root.right, sample)
