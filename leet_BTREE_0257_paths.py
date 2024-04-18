# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def binaryTreePaths(self, root: Optional[TreeNode]) -> List[str]:
        res = []
        def DFS (arr, node, s) -> None:
            if not node.left and not node.right:
                arr.append (s + str(node.val))
            s += str(node.val) + '->'
            if node.left:
                DFS(arr, node.left, s)
            if node.right:
                DFS(arr, node.right, s)
        DFS(res, root, '')
        return res
