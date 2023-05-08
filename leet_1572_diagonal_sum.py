class Solution:
    def diagonalSum(self, mat: List[List[int]]) -> int:
        r = 0
        L = len(mat)
        for i in range(L):
            r += mat[i][i] + mat[i][L - i - 1]
        if L % 2 == 1:
            r -= mat[L // 2][L // 2]
        return r
