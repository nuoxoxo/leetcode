# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def rangeSumBST(self, root: Optional[TreeNode], low: int, high: int) -> int:
        return [
            # self.BFS,
            # self.DFS
            self.Inorder,
        ][ 0 ]( root, low, high )

    def BFS(self, root: Optional[TreeNode], low: int, high: int) -> int:
        Q = deque()
        Q.append(root)
        res = []
        while Q:
            node = Q.popleft()
            if low <= node.val <= high:
                res.append(node.val)
            if node.left:
                Q.append(node.left)
            if node.right:
                Q.append(node.right)
        return sum(res)

    def Inorder(self, root: Optional[TreeNode], low: int, high: int) -> int:
        res = 0
        def traverse(node) -> None:
            if not node:
                return
            traverse(node.left)
            if low <= node.val <= high:
                nonlocal res
                res += node.val
            traverse(node.right)
        traverse(root)
        return res

    def DFS(self, root: Optional[TreeNode], low: int, high: int) -> int:
        res = 0
        def recurse(node):
            if not node:
                return
            nonlocal res
            if low <= node.val <= high:
                res += node.val
            if low < node.val:
                recurse(node.left)
            if node.val < high:
                recurse(node.right)
        recurse(root)
        return res
