
class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        bfs = []
        res = []
        if root is None:
            return []
        bfs.append(root)
        while len(bfs) != 0:
            size = len(bfs)
            temp = []
            while size > 0:
                node = bfs[0]
                bfs.pop(0)
                if node.left:
                    bfs.append(node.left)
                if node.right:
                    bfs.append(node.right)
                temp.append(node.val)
                size -= 1
            res.append(temp)
        return res

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
