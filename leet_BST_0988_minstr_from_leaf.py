# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def smallestFromLeaf(self, root: Optional[TreeNode]) -> str:
        return [
            self.DFS,
        ][ 0 ]( root )

    def DFS(self, root:Optional[TreeNode]) -> str:
        res, curr = '', ''
        def recurse(node, curr) -> str:
            if not node:
                return
            curr = chr(ord('a') + node.val) + curr
            if not node.left and not node.right:
                nonlocal res
                if res == '' or res > curr:
                    res = curr
                return
            recurse(node.left, curr)
            recurse(node.right, curr)
        recurse(root, curr)
        return res

