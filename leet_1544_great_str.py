class Solution:
    def makeGood(self, s: str) -> str:
        dq = []
        for c in s:
            dq.append(c)
            if len(dq) > 1 and dq[-1] != dq[-2] and dq[-1].lower() == dq[-2].lower():
                dq.pop()
                dq.pop()
        return ''.join(dq)
