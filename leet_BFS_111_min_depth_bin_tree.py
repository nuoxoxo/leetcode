# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def minDepth(self, root: Optional[TreeNode]) -> int:
        if root is None:
            return (0)
        E = deque( [ root ] )
        depth = 1
        while E:
            s = len(E)
            for _ in range(s):
                node = E.popleft()
                if node.left is None and node.right is None:
                    return (depth)
                if node.left:
                    E.append(node.left)
                if node.right:
                    E.append(node.right)
            depth += 1
        return (depth)
