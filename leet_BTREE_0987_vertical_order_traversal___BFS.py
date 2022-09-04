# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def verticalTraversal(self, root: Optional[TreeNode]) -> List[List[int]]:
        res = []
        if not root:
            return res
        dq = deque([(root, 0, 0)])
        horizon = defaultdict(list)
        while dq:
            for _ in range(len(dq)):
                node, hpos, depth = dq.popleft() # hpos: horizontal position
                horizon[hpos].append((depth, node.val))
                if node.left:
                    dq.append((node.left, hpos - 1, depth + 1))
                if node.right:
                    dq.append((node.right, hpos + 1, depth + 1))
        for i in sorted(horizon.keys()):
            tmp = []
            for t in sorted(horizon[i]): # tuple, we append the tuple's 2nd val
                tmp.append(t[1])
            res.append(tmp)
        return res
