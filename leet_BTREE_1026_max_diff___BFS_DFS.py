# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxAncestorDiff(self, root: Optional[TreeNode]) -> int:
        return [ self.BFS, self.DFS ][ random.choice([0,1]) ]( root, root.val, root.val )

    # BFS
    def BFS (self, node: TreeNode, L: int, R: int):
        print('/BFS')
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
    def DFS (self, node: TreeNode, L: int, R: int) -> int :
        print('/DFS')
        if not node:
            return R - L
        L = min(L, node.val)
        R = max(R, node.val)
        return int(max( self.DFS(node.left, L, R), self.DFS(node.right, L, R) ))

        
