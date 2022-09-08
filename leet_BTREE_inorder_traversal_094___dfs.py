# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def it(self, node, E):
        if node:
            self.it(node.left, E)
            E.append(node.val)
            self.it(node.right, E)
    def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        E = []
        self.it(root, E)
        return E
