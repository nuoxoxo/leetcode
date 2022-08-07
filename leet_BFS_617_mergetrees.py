# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def mergeTrees(self, r1: Optional[TreeNode], r2: Optional[TreeNode]) -> Optional[TreeNode]:
        if r1 is None:
            return (r2)
        if r2 is None:
            return (r1)
        d1 = deque([r1])
        d2 = deque([r2])
        while d2:
            p1 = d1.popleft()
            p2 = d2.popleft()
            p1.val += p2.val
            if p2.left:
                if p1.left:
                    d1.append(p1.left)
                    d2.append(p2.left)
                else:
                    p1.left = p2.left
            if p2.right:
                if p1.right:
                    d1.append(p1.right)
                    d2.append(p2.right)
                else:
                    p1.right = p2.right
        return (r1)
