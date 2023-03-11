
class Solution:
    def sortedListToBST(self, head: Optional[ListNode]) -> Optional[TreeNode]:
        def make_tree(lst, L, R):
            if L <= R:
                mid = (R - L) // 2 + L
                node = TreeNode(lst[mid])
                node.left = make_tree(lst, L, mid - 1)
                node.right = make_tree(lst, mid + 1, R)
                return node
            return None
        p = head
        lst = []
        while p:
            lst.append(p.val)
            p = p.next
        return make_tree(lst, 0, len(lst) - 1)
            


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
