# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
        res = []
        def dfs(res, level, node) -> None:
            print(level, res)
            if not node:
                return
            if (level == len(res)):
                res.append(node.val)
            else:
                res[level] = node.val
            level += 1
            dfs(res, level, node.left)
            dfs(res, level, node.right)
        dfs(res, 0, root)
        return res
