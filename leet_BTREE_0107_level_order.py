# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def levelOrderBottom(self, root: Optional[TreeNode]) -> List[List[int]]:

        # BFS

        if not root:
            return []
        Q = deque([root])
        res = []
        while Q:
            todo = []
            N = len(Q)
            for _ in range(N):
                node = Q.popleft()
                todo.append(node.val)
                if node.left: Q.append(node.left)
                if node.right: Q.append(node.right)
            res.append(todo)
        return res[::-1]
