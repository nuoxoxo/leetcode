class NumMatrix:

    # self.g = []

    def __init__(self, m: List[List[int]]):
        r, c = len(m), len(m[0])
        self.g = [[0] * (c + 1) for _ in range(r + 1)]
        for i in range(r):
            for j in range(c):
                L = self.g[i + 1][j]
                U = self.g[i][j + 1]
                LU = self.g[i][j]
                self.g[1 + i][1 + j] = m[i][j] + U + L - LU
                

    def sumRegion(self, r1: int, c1: int, r2: int, c2: int) -> int:
        if not self.g:
            return 0
        itself = self.g[r1][c1]
        U = self.g[r1][c2 + 1]
        L = self.g[r2 + 1][c1]
        DR = self.g[1 + r2][1 + c2]
        return itself + DR - U - L


# Your NumMatrix object will be instantiated and called as such:
# obj = NumMatrix(matrix)
# param_1 = obj.sumRegion(row1,col1,row2,col2)
