# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def splitListToParts(self, head: Optional[ListNode], k: int) -> List[Optional[ListNode]]:
        res = []
        N = 0
        p = head
        while p:
            N += 1
            p = p.next
        slotSize = N // k
        remainingSlots = N % k
        p = head
        # print(N, slotSize, remainingSlots)
        for _ in range(k):
            res.append(p)
            tail_maybe = None
            for _ in range(slotSize):
                if p:
                    tail_maybe = p
                    p = p.next
            if p and remainingSlots > 0:
                tail_maybe = p
                p = p.next
                remainingSlots -= 1
            if tail_maybe:
                tail_maybe.next = None
        return res
