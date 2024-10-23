# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def replaceValueInTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        # double DFS - 1. populate the level_total
        level_total = []
        def dfs_get_level_total(node: Optional[TreeNode], depth: int) -> None:
            if not node:
                return
            if depth > len(level_total) - 1:
                level_total.append(0)
            level_total[ depth ] += node.val
            dfs_get_level_total(node.left, depth + 1)
            dfs_get_level_total(node.right, depth + 1)

        dfs_get_level_total(root, 0)
        # print(level_total)

        # 2. change each node's value

        def dfs_do_stuff(node: Optional[TreeNode], depth:int, cousin_total: int) -> None:
            if not node:
                return
            node.val = level_total[ depth ] - cousin_total
            curr_cousins = 0
            if node.left:
                curr_cousins += node.left.val
            if node.right:
                curr_cousins += node.right.val
            dfs_do_stuff(node.left, depth + 1, curr_cousins)
            dfs_do_stuff(node.right, depth + 1, curr_cousins)

        dfs_do_stuff(root, 0, root.val)
        return root




