class Solution:
    def construct2DArray(self, original: List[int], m: int, n: int) -> List[List[int]]:
        N = len(original)
        if m * n != N:
            return []
        i = 0
        res = [[0 for _ in range(n)] for _ in range(m)]
        for r in range(m):
            for c in range(n):
                res[r][c] = original[i]
                i += 1
        return res
