# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def minDiffInBST(self, root: Optional[TreeNode]) -> int:
        def inorder(node, arr):
            if not node:
                return 
            inorder(node.left, arr)
            arr.append(node.val)
            inorder(node.right, arr)
        arr = []
        inorder(root, arr)
        arr.sort(reverse=True)
        res = 1e9
        for i in range(len(arr) - 1):
            diff = arr[i] - arr[i + 1]
            if res > diff:
                res = diff
        return res

