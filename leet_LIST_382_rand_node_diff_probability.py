class Solution:

    def __init__(self, head: Optional[ListNode]):
        self.h = head

    def getRandom(self) -> int:
        p = self.h
        pos = 1
        while p is not None:
            if random.random() < (1/pos):
                res = p.val
            p = p.next
            pos += 1
        return res
