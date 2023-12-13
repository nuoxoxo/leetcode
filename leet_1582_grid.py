class Solution:
    def numSpecial(self, mat: List[List[int]]) -> int:
        R = defaultdict(int)
        C = defaultdict(int)
        for r in range(0, len(mat)):
            for c in range(0, len(mat[0])):
                if mat[r][c] == 1:
                    R[r] += 1
                    C[c] += 1
        res = 0
        for r in range(0, len(mat)):
            for c in range(0, len(mat[0])):
                if mat[r][c] == R[r] == C[c] == 1:
                    res += 1
        return res
