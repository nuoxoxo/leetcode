class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        res = max(piles)
        R = res
        L = 1
        while L < R + 1:
            mid = (L + R) // 2
            t = 0
            for p in piles:
                t += ceil(p / mid)
            if t > h:
                L = mid + 1
            else:
                R = mid - 1
                res = min(res, mid)
        return res
