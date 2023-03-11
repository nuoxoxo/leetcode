# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        def dfs(res, node, level) -> None:
            if node is None:
                return
            if len(res) == level:
                res.append([])
            res[level].append(node.val)
            dfs(res, node.left, level + 1)
            dfs(res, node.right, level + 1)
        if root is None:
            return []
        res = []
        dfs(res, root, 0)
        return res
