# Preorder (Root, Left, Right)

class Solution:
    def dfs(self, node, E):
        if node is not None:
            E.append(node.val)
            self.dfs(node.left, E)
            self.dfs(node.right, E)
    def preorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        E = []
        self.dfs(root, E)
        return E

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
