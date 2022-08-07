class Solution:
    def matrixReshape(self, mat: List[List[int]], r: int, c: int) -> List[List[int]]:
        co = len(mat[0])
        ro = len(mat)
        if r*c != ro*co:
            return mat
        res = [[0 for i in range(c)] for j in range(r)]
        for i in range(r * c):
            res[i // c][i % c] = mat[i // co][i % co]
        return res 
