
class Solution:
    def swapPairs(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head is None or head.next is None:
            return head

        temp = ListNode()
        temp.next = head
        prev = temp
        curr = head
        while curr and curr.next:
            prev.next = curr.next
            curr.next = curr.next.next
            prev.next.next = curr

            prev = curr
            curr = curr.next
        return temp.next
