class Solution:
    def getAllElements(self, root1: TreeNode, root2: TreeNode) -> List[int]:
        E = []
        self.fill(root1, E)
        self.fill(root2, E)
        E.sort()
        return E

    def fill(self, r: TreeNode, E: List[int]):
        if r is None:
            return
        self.fill(r.right, E)
        E.append(r.val)
        self.fill(r.left, E)
