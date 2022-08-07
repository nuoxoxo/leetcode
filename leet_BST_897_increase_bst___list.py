# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def increasingBST(self, root: TreeNode) -> TreeNode:
        def inorder_traversal(node):
            if node:
                inorder_traversal(node.left)
                nodes.append(node)
                inorder_traversal(node.right)
        nodes = []
        inorder_traversal(root)
        for i in range(len(nodes) - 1):
            nodes[i].right = nodes[i + 1]
            nodes[i].left = None
        nodes[-1].right = None
        nodes[-1].left = None
        return nodes[0]
