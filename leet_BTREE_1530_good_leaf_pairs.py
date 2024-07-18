# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def countPairs(self, root: TreeNode, distance: int) -> int:
        caching = {}
        cached = defaultdict(bool)
        res = 0
        def dfs (node: TreeNode) -> dict:#Dict[int, int]: # also works
            if not node:
                return defaultdict(int)
            if cached[node]:
                return caching[node]
            nonlocal res
            L = dfs(node.left)
            R = dfs(node.right)
            if not L and not R:
                cached[node] = True
                caching[node] = {0:1}
                return {0:1}
            # O(n^2)
            counter = defaultdict(int)
            for leftdepth, x in L.items():
                for rightdepth, y in R.items():
                    if leftdepth + 1 + rightdepth + 1 <= distance:
                        res += x * y
            for k, v in L.items():
                counter[k + 1] += v
            for k, v in R.items():
                counter[k + 1] += v
            cached[node] = True
            caching[node] = counter
            return counter
        print(dfs(root))
        return res
                

