class Solution:
    def deleteDuplicates(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head:
            return None
        dumm = ListNode(0)
        slow = dumm
        fast = head
        while fast:
            if fast.next and fast.val == fast.next.val:
                while fast.next and fast.val == fast.next.val:
                    fast = fast.next
            else:
                slow.next = fast
                slow = fast
            fast = fast.next
        slow.next = None
        # edge case where from 2nd node on all nodes are equal
        dumm = dumm.next
        return dumm
