# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def removeLeafNodes(self, root: Optional[TreeNode], target: int) -> Optional[TreeNode]:
        return [
            # DFS,
            Simple_post_order_traversal,
        ][0](root, target)

def DFS(root: Optional[TreeNode], T:int) -> None:
    def Recurse(node: Optional[TreeNode], T:int) -> None:
        if not node:
            return
        Recurse(node.left, T)
        if node.left and node.left.val == 0:
            node.left = None
        Recurse(node.right, T)
        if node.right and node.right.val == 0:
            node.right = None
        # when we get to a Leaf, mark it first
        if not node.left and not node.right and node.val == T:
            node.val = 0
    Recurse(root, T)
    assert not root.left and not root.right if root.val == 0 else True
    # Root has to be a Leaf IIF root is marked
    if root.val == 0 and not root.left and not root.right:
        return None
    return root

def Simple_post_order_traversal(root: Optional[TreeNode], T:int) -> None:
    if not root:
        return None

    root.left = Simple_post_order_traversal(root.left, T)
    root.right = Simple_post_order_traversal(root.right, T)

    if root.val == T and not root.left and not root.right:
        return None
    return root
