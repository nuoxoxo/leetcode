# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def evaluateTree(self, root: Optional[TreeNode]) -> bool:
        return [
            # BFS_level_dict_and_bitwise_each_level, # non-recursive
            Recursive,
        ][0](root)

def Recursive(root: Optional[TreeNode]) -> bool:
    assert root
    n = root.val
    if n in [0, 1]:
        return n
    if n == 2: # -> OR
        return Recursive(root.left) or Recursive(root.right)
    return Recursive(root.left) and Recursive(root.right) # 3 -> AND

def BFS_level_dict_and_bitwise_each_level(root: Optional[TreeNode]) -> bool:
    D = defaultdict(list)
    Q = deque([root])
    depth = -1
    while Q:
        depth += 1
        N = len(Q)
        for _ in range(N):
            node = Q.popleft()
            D[depth].append(node)
            if node.left:
                Q.append(node.left)
            if node.right:
                Q.append(node.right)
    # printer(D) # dbg
    if depth != 0:
        for level in range(depth - 1, -1, -1):
            for node in D[level]:
                if node.val in [0, 1]: continue
                assert node.left and node.right
                L, R = node.left.val, node.right.val
                if node.val == 2: # OR
                    node.val = L | R
                elif node.val == 3: # AND
                    node.val = L & R
    assert root.val in [True, False]
    return root.val

def printer(D):
    for l, r in D.items():
        for n in r:
            if n.val == 2: n = 'OR'
            elif n.val == 3: n = 'AND'
            else: n = n.val
            print(l, n)
        print()
