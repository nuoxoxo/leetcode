# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def leafSimilar(self, root1: Optional[TreeNode], root2: Optional[TreeNode]) -> bool:
        def dfs_on_single_tree(node: TreeNode, a: List[int]) -> None:
            if not node:
                return
            if not node.left and not node.right:
                a.append(node.val)
            dfs_on_single_tree(node.left, a)
            dfs_on_single_tree(node.right, a)
        a1 = []
        a2 = []
        dfs_on_single_tree(root1, a1)
        dfs_on_single_tree(root2, a2)
        return a1 == a2
