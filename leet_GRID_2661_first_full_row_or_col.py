class Solution:
    def firstCompleteIndex(self, arr: List[int], mat: List[List[int]]) -> int:
        R,C = len(mat), len(mat[0])
        rc,rowcount,colcount = {},[0] * R, [0] * C
        for r in range(R):
            for c in range(C):
                n = mat[r][c]
                rc[n] = (r,c)
        for i,n in enumerate(arr):
            r,c = rc[n]
            rowcount[r] += 1
            if rowcount[r] == C: # bugfix/ we check if any cell on row 'r' reaches C
                return i
            colcount[c] += 1
            if colcount[c] == R:
                return i
        assert False


