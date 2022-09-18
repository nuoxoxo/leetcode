class Solution:
    def trap(self, h: List[int]) -> int:
        R = len(h) - 1
        L = 0
        HR, HL = 0, 0
        res = 0
        while L <= R:
            if HL < HR:
                HL = max(HL, h[L])
                res += HL - h[L]
                L += 1
            else:
                HR = max(HR, h[R])
                res += HR - h[R]
                R -= 1
        return res
