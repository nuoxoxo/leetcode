# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def getDirections(self, root: Optional[TreeNode], startValue: int, destValue: int) -> str:
        # [5,1,2,3,null,6,4] -> we know that
        #   path 1: root -> (s=3): LL
        #   path 2: root -> (e=6): RL 
        # path 1 is in fact upward: LL -> UU
        # ps. both path are in fact backward in DFS
        # res -> UURL
        def find(path: Deque[str], node: TreeNode, tar: int) -> bool:
            # DFS
            if not node:
                return False
            if node.val == tar:
                return True
            if find(path, node.left, tar):
                path.appendleft('L')
                return True
            if find(path, node.right, tar):
                path.appendleft('R')
                return True
            return False
        up = deque()
        down = deque()
        find(up, root, startValue)
        find(down, root, destValue)
        while up and down and up[0] == down[0]:
            up.popleft()
            down.popleft()
        l = len(up) * 'U'
        r = ''.join(down)
        return l + r
            
