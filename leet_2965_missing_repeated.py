class Solution:
    def findMissingAndRepeatedValues(self, grid: List[List[int]]) -> List[int]:
        return [
            # Using_set,
            Using_DP,
        ][0](grid)

def Using_DP(grid: List[List[int]]) -> List[int]:
    N = len(grid)
    dp = [0] * (N*N + 1)
    res = [None,None]
    for r in range(N):
        for c in range(N): dp[ grid[r][c] ] += 1
    for n in range(1, N*N + 1):
        if dp[n] > 1: res[0] = n
        elif dp[n] == 0: res[1] = n
        if res[0] != None and res[1] != None:
            return res
    assert False

def Using_set(grid: List[List[int]]) -> List[int]:
    res = None
    N = len(grid)
    seen = set([_ for _ in range(1,N*N+1)])
    for r in range(N):
        for c in range(N):
            n = grid[r][c]
            if n not in seen:
                res = n
            else:
                seen.remove(n)
    assert len(seen) == 1
    return [res, list(seen).pop()]


