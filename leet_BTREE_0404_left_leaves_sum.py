# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sumOfLeftLeaves(self, root: Optional[TreeNode]) -> int:
        return [
            # self.dfs1,
            # self.dfs2,
            self.BFS,
        ][ 0 ]( root )

    def BFS(self, root) -> int:
        res = 0
        Q = [(root, False)]
        while Q:
            node, LEFT = Q.pop()
            if LEFT and not node.left and not node.right:
                res += node.val
            if node.left:
                Q.append( (node.left, True) )
            if node.right:
                Q.append( (node.right, False) )
        return res

    # Better DFS
    def dfs2(self, root) -> int:
        def DFS(node, LEFT) -> int:
            if not node:
                return 0
            if not node.left and not node.right:
                if not LEFT:
                    return 0
                return node.val
            return DFS(node.left, True) + DFS(node.right, False)
        return DFS(root, False)


    def dfs1(self, root) -> int:
        def DFS(node) -> int:
            if not node:
                return 0
            if node.left and not node.left.left and not node.left.right:
                return node.left.val + DFS (node.right)
            return DFS(node.left) + DFS(node.right)
        return DFS(root)

