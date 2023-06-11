class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        """Do not return anything, modify matrix in-place instead."""
        pts = []
        for i in range(len(matrix)):
            for j in range(len(matrix[0])):
                if matrix[i][j] == 0:
                    pts.append( (i, j) )
        for p in pts:
            for i in range(len(matrix)):
                matrix[i][ p[1] ] = 0
            for i in range(len(matrix[0])):
                matrix[ p[0] ][i] = 0
