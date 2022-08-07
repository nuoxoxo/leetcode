class Solution:
    def findBottomLeftValue(self, root: Optional[TreeNode]) -> int:
        dq = [root]
        last = root
        while dq:
            node = dq.pop(0)
            last = node
            if node.right:
                dq.append(node.right)
            if node.left:
                dq.append(node.left)
        return last.val

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
