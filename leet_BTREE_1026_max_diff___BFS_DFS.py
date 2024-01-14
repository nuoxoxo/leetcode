# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxAncestorDiff(self, root: Optional[TreeNode]) -> int:

        # BFS
        def BFS (node: TreeNode, L: int, R: int):
            D = [ (node, L, R) ]
            res = 0
            while D:
                node, hi, lo = D.pop(0)
                hi = max(node.val, hi)
                lo = min(node.val, lo)
                if node.left:
                    D.append( (node.left, hi, lo) )
                if node.right:
                    D.append( (node.right, hi, lo) )
                res = max(res, hi - lo)
            return res

        # DFS
        def finder (node: TreeNode, L: int, R: int) -> int :
            if not node:
                return R - L
            L = min(L, node.val)
            R = max(R, node.val)
            return int(max( finder(node.left, L, R), finder(node.right, L, R) ))

        n = random.choice([0,1])
        print( ['BFS','DFS'][ n ] )
        return [ BFS, finder ][ n ](root, root.val, root.val)
