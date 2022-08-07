class Solution:
    def invertTree(self, node: Optional[TreeNode]) -> Optional[TreeNode]:
        if node is None:
            return None
        node.left, node.right = node.right, node.left
        self.invertTree(node.left)
        self.invertTree(node.right)
        return node
