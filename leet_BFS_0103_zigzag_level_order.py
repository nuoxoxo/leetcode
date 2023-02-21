# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def zigzagLevelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        if not root:
            return []
        D = deque([root])
        count = 0
        r = []
        while D:
            temp = []
            size = len(D)
            while size > 0:
                node = D.popleft()
                temp.append(node.val)
                if node.left:
                    D.append(node.left)
                if node.right:
                    D.append(node.right)
                size -= 1
            if count % 2 ^ 0:
                r.append(temp[::-1])
            else:
                r.append(temp)
            count += 1
        return r
