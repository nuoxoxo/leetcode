class Solution:
    def transpose(self, matrix: List[List[int]]) -> List[List[int]]:
        res = []
        for c in range(len(matrix[0])):
            tmp = []
            for r in range(len(matrix)):
                tmp.append(matrix[r][c])
            res.append(tmp)
        return res
