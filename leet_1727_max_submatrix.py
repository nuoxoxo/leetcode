class Solution:
    def largestSubmatrix(self, matrix: List[List[int]]) -> int:
        R = len(matrix)
        C = len(matrix[0])
        
        for r in range(1, R):
            for c in range(C):
                if matrix[r - 1][c] and matrix[r][c]:
                    matrix[r][c] += matrix[r - 1][c]
        res = 0
        for row in matrix:
            row.sort()
            # row.sort(reverse=True)
            for c in range(C):
                h = row[c]
                w = C - c# c + 1
                res = max(res, w * h)
        return res
