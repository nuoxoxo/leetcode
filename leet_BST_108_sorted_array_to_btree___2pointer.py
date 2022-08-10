# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def sortedArrayToBST(self, nums: List[int]) -> Optional[TreeNode]:
        def make_tree(nums, L, R):
            if L > R:
                return None
            midpoint = (R - L) // 2 + L
            temp = TreeNode(nums[midpoint])
            temp.left = make_tree(nums, L, midpoint - 1)
            temp.right = make_tree(nums, midpoint + 1, R)
            return temp
        return make_tree(nums, 0, len(nums) - 1)
