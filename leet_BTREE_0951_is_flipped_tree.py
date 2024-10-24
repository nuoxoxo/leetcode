# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def flipEquiv(self, root1: Optional[TreeNode], root2: Optional[TreeNode]) -> bool:
        def check(L: Optional[TreeNode], R: Optional[TreeNode]) -> bool:
            # bottom case
            if not L and not R:
                return True
            # if the two are different
            if L and not R or not L and R or L.val != R.val:
                return False
            # if the two are the same or flipped
            return check(L.left, R.left) and check(L.right, R.right) \
                or check(L.left, R.right) and check(L.right, R.left)
        return check(root1, root2)
"""
[0,2,1,4,null,3,5,null,null,6,7]
[0,2,1,4,null,3,5,null,null,null,6,7]
"""
