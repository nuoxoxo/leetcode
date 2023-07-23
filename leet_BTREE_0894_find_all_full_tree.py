# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def allPossibleFBT(self, n: int) -> List[Optional[TreeNode]]:
        if n == 1:
            return [ TreeNode() ]
        if n % 2 == 0: # no full tree is possible
            return []

        res = []
        i = 1
        # print('here')
        while i < n - 1:
            # print('here2')
            L = self.allPossibleFBT(i)
            R = self.allPossibleFBT(n - i - 1)
            for l in L:
                # print('here3')
                for r in R:
                    node = TreeNode() # root of a new subtree
                    node.left = l
                    node.right = r
                    res.append(node)
            i += 2
        return res

