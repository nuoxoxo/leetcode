# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def addOneRow(self, root: Optional[TreeNode], val: int, depth: int) -> Optional[TreeNode]:
        return [
            # self.DFS,
            self.BFS,
        ][0](root, val, depth)

    def BFS(self, root, val, depth) -> Optional[TreeNode]:
        assert root
        if depth == 1:
            node = TreeNode(val)
            node.left = root
            return node
        Q = deque()
        Q.append(root)
        while Q:
            depth -= 1
            if depth == 0:
                return root
            N = len(Q)
            for _ in range(N):
                node = Q.popleft()
                if depth == 1 :
                    L, R = TreeNode(val), TreeNode(val)
                    L.left = node.left
                    R.right = node.right
                    node.left, node.right = L, R
                else:
                    if node.left:
                        Q.append(node.left)
                    if node.right:
                        Q.append(node.right)
        return root

    def DFS(self, root, val, depth) -> Optional[TreeNode]:
        if not root:
            return None
        if depth == 1:
            node = TreeNode(val)
            node.left = root
            return node
        if depth == 2:
            L, R = TreeNode(val), TreeNode(val)
            L.left = root.left
            R.right = root.right
            root.left = L
            root.right = R
            return root
        root.left = self.DFS(root.left, val, depth - 1)
        root.right = self.DFS(root.right, val, depth - 1)
        return root


