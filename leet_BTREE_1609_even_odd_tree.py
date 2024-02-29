# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isEvenOddTree(self, root: Optional[TreeNode]) -> bool:
        return [
            self.Solution_BFS,
            # self.Solution_DFS,
        ][ 0 ]( root )

    def Solution_BFS (self, root: Optional[TreeNode]) -> bool:
        dq = [root]
        level = 0
        while dq:
            # for node in dq: print(node.val, end=' ')
            # print()
            level += 1
            temp = []
            prev = 0 #-1e9
            for node in dq:
                isEven = level % 2 == 0
                # level even :: strictly increasing order    
                if node.val % 2 == isEven or \
                isEven and prev > 0 and prev <= node.val or \
                not isEven and prev >= node.val:
                # level odd .. decreasing
                    return False
                prev = node.val
                if node.left:
                    temp.append(node.left)
                if node.right:
                    temp.append(node.right)
                prev = node.val
            dq = temp
        return True

