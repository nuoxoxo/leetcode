class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        """Do not return anything, modify matrix in-place instead."""
        cols = len(matrix[0])
        rows = len(matrix)
        r = [1] * rows
        c = [1] * cols
        for i in range(rows):
            for j in range(cols):
                if matrix[i][j] is 0 :
                    r[i] = 0
                    c[j] = 0
        for i in range(rows):
            for j in range(cols):
                if r[i] is 0 or c[j] is 0 :
                    matrix[i][j] = 0
