# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right


"""BFS"""


class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        if root is None:
            return 0
        E = deque( [root] )
        depth = 0
        while E:
            for _ in range(len(E)):
                node = E.popleft()
                if node.left:   E.append(node.left)
                if node.right:  E.append(node.right)
            depth += 1
        return depth
