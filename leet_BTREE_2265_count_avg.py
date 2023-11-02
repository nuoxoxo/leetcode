# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def averageOfSubtree(self, root):
        def BFS(node):
            nonlocal res
            sum_val = 0
            sum_node = 0
            D = [node]
            while D:
                size = len(D)
                for _ in range(size):
                    n = D.pop(0)
                    sum_val += n.val
                    sum_node += 1
                    if n.left:
                        D.append(n.left)
                    if n.right:
                        D.append(n.right)
            if sum_val // sum_node == node.val:
                res += 1
        res = 0
        D = [root]
        while D:
            size = len(D)
            for _ in range(size):
                node = D.pop(0)
                BFS(node)
                if node.left:
                    D.append(node.left)
                if node.right:
                    D.append(node.right)
        return res

