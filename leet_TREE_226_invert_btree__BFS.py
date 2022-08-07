# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right


class Solution:
    def invertTree(self, node: Optional[TreeNode]) -> Optional[TreeNode]:
        if not node:
            return node
        q = deque()
        q.append(node)
        while q:
            temp = q.popleft()
            temp.left, temp.right = temp.right, temp.left
            if temp.left:
                q.append(temp.left)
            if temp.right:
                q.append(temp.right)
        return node
        


