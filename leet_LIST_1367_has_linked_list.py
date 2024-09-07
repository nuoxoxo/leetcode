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
        def compare_subtree(head, node) -> bool:
            if not head:
                return True
            if not node or node.val != head.val:
                return False
            return compare_subtree(head.next, node.left) or compare_subtree(head.next, node.right)
        def dfs(node) -> bool:
            if not node:
                return False
            return compare_subtree(head, node) or dfs(node.left) or dfs(node.right)
        return dfs(root)
