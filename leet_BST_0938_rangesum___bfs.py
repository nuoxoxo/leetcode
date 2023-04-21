# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def rangeSumBST(self, root: Optional[TreeNode], low: int, high: int) -> int:
        D = [root]
        a = []
        while D:
            temp = D.pop(0)
            n = temp.val
            if n <= high and n >= low:
                a.append(n)
            if temp.left:
                D.append(temp.left)
            if temp.right:
                D.append(temp.right)
        return sum(a)

