class Solution:
    def minOperations(self, grid: List[List[int]], x: int) -> int:
        F = []# flattened
        for r in grid:
            F.extend(r)
        F.sort()
        res = 0
        med = F[len(F) // 2]
        for n in F:
            diff = abs(n - med)
            if diff % x != 0:
                return -1
            res += diff // x
        return res
        
