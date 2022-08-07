class Solution:
    def diagonalSum(self, mat: List[List[int]]) -> int:
        r = len(mat)
        if r is 0:
            return mat[0][0]
        t = 0
        for i in range(r):
            for j in range(r):
                if i is j or r - i is j + 1:
                    t += mat[i][j]
        return t
