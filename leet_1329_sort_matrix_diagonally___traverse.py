class Solution:
    def diagonalSort(self, mat: List[List[int]]) -> List[List[int]]:
        r = len(mat)
        c = len(mat[0])
        res = [[0 for _ in range(c)] for _ in range(r)]
        for d in range(c * (-1), r):
            temp = []
            for i in range(r):
                j = i - d
                if -1 < j < c:
                    temp.append(mat[i][j])
            temp.sort()
            t = 0
            for i in range(r):
                j = i - d
                if -1 < j < c:
                    res[i][j] = temp[t]
                    t += 1
        return res
