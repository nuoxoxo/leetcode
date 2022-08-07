# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right


class Solution:
    def recoverTree(self, root: Optional[TreeNode]) -> None:
        """
        Do not return anything, modify root in-place instead.
        """

        def iot(node):
            if not node:
                return
            iot(node.left)
            self.n.append(node.val)
            iot(node.right)

        def heal(node):
            if node:
                heal(node.left)
                if self.n[self.i] != node.val:
                    node.val, self.n[self.i] = self.n[self.i], node.val
                self.i += 1
                heal(node.right)

        self.n = []
        self.i = 0
        iot(root)
        self.n.sort()
        heal(root)
