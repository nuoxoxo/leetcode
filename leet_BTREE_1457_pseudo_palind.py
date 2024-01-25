# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def pseudoPalindromicPaths (self, root: Optional[TreeNode]) -> int:
        return [
            self.Solution_BFS_bitmask,
            self.Solution_BFS_counting,
        ][ random.randint(0,1) ]( root )
    def Solution_BFS_bitmask(self, root: TreeNode) -> int:
        def Flipper (bitmask_of_10, n):
            # we encounter N.
            # to flip n's even-odd state we flip its N-th bit
            # ( this is possible because n is in range [0,9] )
            return bitmask_of_10 ^ (1 << (n - 1))
        def Checker(bm10):
            # check if bitmask has exactly one bit of '1'
            # (bm10 - 1) : set all bits to the right of the rightmost set bit
            # bm10 & (bm10 - 1) : 
                # if only one bit is set, then it must be the rightmost set bit
                # if more than one bit is set, the &= results in non-0
            return bm10 & (bm10 - 1) == 0
        dq = deque()
        dq.append( (root, Flipper(0, root.val )) )
        res = 0
        while dq:
            node, state = dq.popleft()
            if not node.left and not node.right and Checker(state):
                res += 1
            if node.left:
                dq.append( (node.left, Flipper(state, node.left.val)) )
            if node.right:
                dq.append( (node.right, Flipper(state, node.right.val)) )
        return res



    def Solution_BFS_counting(self, root: TreeNode) -> int:
        def Flip(arr, n):
            arr[n - 1] = not arr[n - 1]
            return arr
        res = 0
        DQ = deque()
        a = [False] * 9
        DQ.append( (root, Flip(a, root.val)) )
        while DQ:
            node, arr = DQ.popleft()
            if node.left:
                DQ.append( (node.left, Flip(arr.copy(), node.left.val)) )
            if node.right:
                DQ.append( (node.right, Flip(arr.copy(), node.right.val)) )
            if not node.left and not node.right:
                if len([_ for _ in arr if _]) in [0,1]:
                    res += 1
        return res
