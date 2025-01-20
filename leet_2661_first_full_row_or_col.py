class Solution:
    def firstCompleteIndex(self, arr: List[int], mat: List[List[int]]) -> int:
        R,C = len(mat), len(mat[0])
        rows,cols,rowcount,colcount = {},{},collections.defaultdict(int),collections.defaultdict(int)
        for r in range(R):
            for c in range(C):
                n = mat[r][c]
                rows[n] = r
                cols[n] = c
        # print(rows,cols)
        for i,n in enumerate(arr):
            r,c = rows[n],cols[n]
            rowcount[r] += 1
            if rowcount[r] == C: # bugfix/ we check if any cell on row 'r' reaches C
                # print('r/',n,r,rowcount[r],R)
                return i
            colcount[c] += 1
            if colcount[c] == R:
                # print('c/',n,c,colcount[r],C)
                return i
        assert False


