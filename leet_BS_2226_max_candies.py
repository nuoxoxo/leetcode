class Solution:
    def maximumCandies(self, candies: List[int], k: int) -> int:

        def check(C:List[int], k:int, i:int) -> bool:
            res = 0
            for c in C:
                res += c // i
            return not res < k

        L, R = 0, max(candies)
        while L < R:
            mid = (L + R + 1) // 2
            if check(candies,k,mid):
                L = mid
            else:
                R = mid - 1
        return L

