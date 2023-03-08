class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        piles.sort()
        M = piles[-1]
        L = 1
        R = M
        res = M
        while L < R:
            hours = 0
            mid = (R - L) // 2 + L
            for p in piles:
                hours += ceil(p / mid)
            if hours > h:
                L = mid + 1
            else:
                res = min(res, mid)
                R = mid
        return res
