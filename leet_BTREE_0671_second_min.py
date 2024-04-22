# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def findSecondMinimumValue(self, root: Optional[TreeNode]) -> int:
        return [
            # self.BFS_with_set,
            # self.BFS_economic,
            self.DFS,
        ][0](root)

    def DFS(self, root: Optional[TreeNode]) -> int:
        res0, res1 = 2147483648, 2147483648
        def recurse(node: Optional[TreeNode]) -> None:
            if not node:
                return
            n = node.val
            nonlocal res0, res1
            if n < res0:
                res1 = res0
                res0 = n
            elif n != res0 and n < res1:
                res1 = n
            recurse(node.left)
            recurse(node.right)
        recurse(root)
        if res1 != 2147483648:
            return res1
        return -1

    def BFS_economic(self, root: Optional[TreeNode]) -> int:

        res = [2147483648, 2147483648]
        Q = deque()
        Q.append(root)
        while Q:
            node = Q.popleft()
            n = node.val
            if n < res[0]:
                res[1] = res[0]
                res[0] = n
            elif n != res[0] and n < res[1]:
                res[1] = n
            if node.left:
                Q.append(node.left)
            if node.right:
                Q.append(node.right)
        if res[1] == 2147483648:
            return -1
        return res[1]

    def BFS_with_set(self, root: Optional[TreeNode]) -> int:

        Q = deque()
        Q.append(root)
        S = set()
        while Q:
            node = Q.popleft()
            n = node.val
            S.add(n)
            if node.left:
                Q.append(node.left)
            if node.right:
                Q.append(node.right)
        res = list(S)
        if len(res) < 2:
            return -1
        return sorted(res)[1]
