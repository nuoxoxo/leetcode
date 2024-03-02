# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def findBottomLeftValue(self, root: Optional[TreeNode]) -> int:
        return [
            self.BFS, # preferred
            self.DFS, # struggling
        ][ 1 ]( root )

    def BFS(self, root:Optional[TreeNode]) -> int:
        Q = deque()
        Q.append(root)
        res = root
        while Q:
            node = Q.popleft()
            if node.right:
                Q.append(node.right)
            if node.left:
                Q.append(node.left)
        return node.val

    # 1st elem of the N-th level when N=height
    def DFS(self, root:Optional[TreeNode]) -> int:
        res = 0
        max_depth = -1
        def solver(node, level):
            if not node:
                return
            if not node.left:
                nonlocal res, max_depth
                if max_depth < level:
                    res = node.val
                    max_depth = level
            solver(node.left, level + 1)
            solver(node.right, level + 1)
        solver( root, 0 )
        return res
