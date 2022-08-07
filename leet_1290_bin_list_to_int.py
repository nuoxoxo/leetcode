class Solution:
    def getDecimalValue(self, head: ListNode) -> int:
        p = head
        bis = ""
        while p is not None:
            bis += str(p.val)
            p = p.next
        return int(bis, 2)
