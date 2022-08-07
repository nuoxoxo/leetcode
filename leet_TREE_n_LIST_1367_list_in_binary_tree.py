# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def isSubPath(self, head: Optional[ListNode], root: Optional[TreeNode]) -> bool:
        def cmp(head: ListNode, root: TreeNode) -> bool:
            if head is None:
                return True
            if root is None or root.val != head.val:
                return False
            return cmp(head.next, root.left) or cmp(head.next, root.right)
        def dfs(head: ListNode, root: TreeNode) -> bool:
            if root is None:
                return False
            if cmp(head, root):
                return True
            return dfs(head, root.left) or dfs(head, root.right)
        return dfs(head, root)
