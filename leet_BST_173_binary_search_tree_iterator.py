# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class BSTIterator:

    def __init__(self, node: Optional[TreeNode]):
        self.i = 0
        self.arr = []
        def inorder_traversal(self, node: Optional[TreeNode]):
            if not node:
                return
            inorder_traversal(self, node.left)
            self.arr.append(node.val)
            inorder_traversal(self, node.right)
        inorder_traversal(self, node)


    def next(self) -> int:
        n = len(self.arr)
        if self.i < n:
            val = self.arr[self.i]
        else:
            val = self.arr[n - 1]
        self.i += 1
        return val


    def hasNext(self) -> bool:
        return self.i < len(self.arr)


# Your BSTIterator object will be instantiated and called as such:
# obj = BSTIterator(root)
# param_1 = obj.next()
# param_2 = obj.hasNext()
