class Solution:
    def restoreMatrix(self, rowSum: List[int], colSum: List[int]) -> List[List[int]]:
        return [
            More_efficient, # O(R+C)
            # Initial_soln, # O(R x C)
        ][0](rowSum, colSum)

def More_efficient(rowSum: List[int], colSum: List[int]) -> List[List[int]]:
    R, C = len(rowSum), len(colSum)
    res = [[0] * C for _ in range(R)]
    r, c = 0, 0
    while r < R and c < C:
        res[r][c] = min(rowSum[r], colSum[c])
        rowSum[r] -= res[r][c]
        colSum[c] -= res[r][c]
        while r < R and rowSum[r] == 0:
            r += 1
        while c < C and colSum[c] == 0:
            c += 1
    return res

def Initial_soln(rowSum: List[int], colSum: List[int]) -> List[List[int]]:
    """
        4  7
    3
    8
    ->
        (4)(7)
    (3)  3  0
    (8)  1  7
    """
    R, C = len(rowSum), len(colSum)
    res = [[0] * C for _ in range(R)]
    for r in range(R):
        for c in range(C):
            res[r][c] = min(rowSum[r], colSum[c])
            rowSum[r] -= res[r][c]
            colSum[c] -= res[r][c]
            # for _ in res:print(_)
            # print()
    assert min(rowSum) == max(rowSum) == min(colSum) == max(colSum)
    return res
