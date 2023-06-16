# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def reverseOddLevels(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        if not root:
            return root
        dq = [root]
        line = []
        level = 0
        while dq:
            kids = []
            size = len(dq)
            for _ in range(size):
                node = dq.pop(0)
                if level % 2 != 0:
                    node.val = line[size - 1 - _]
                if node.left:
                    dq.append(node.left)
                    kids.append(node.left.val)
                if node.right:
                    dq.append(node.right)
                    kids.append(node.right.val)
            line = kids
            level += 1
        return root
                
