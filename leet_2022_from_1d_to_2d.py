class Solution:
    def construct2DArray(self, original: List[int], m: int, n: int) -> List[List[int]]:
        S = len(original)
        if m * n != S:
            return []
        r = [[0] * n for _ in range(m)]
        k = 0
        for i in range(m):
            for j in range(n):
                r[i][j] = original[k]
                k += 1
        return r
