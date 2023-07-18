# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def countNodes(self, root: Optional[TreeNode]) -> int:
        if not root:
            return 0
        D = [ root ]
        res = 0
        while D:
            for i in range(len(D)):
                node = D.pop(0)
                if node.left:
                    D.append( node.left )
                if node.right:
                    D.append( node.right )
                res += 1
        return res



