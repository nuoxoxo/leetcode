class Solution:
    def matrixScore(self, grid: List[List[int]]) -> int:
        return [
            Greedy_cols,
        ][0](grid)

def Greedy_cols(G: List[List[int]]) -> int:
    R = len(G)
    C = len(G[0])
    # 1/3 - maximize rows
    #   - most significant flipped if 0
    for r in range(R):
        if G[r][0] == 0:
            for c in range(C):
                G[r][c] ^= 1
                # G[r][c] = 1 - G[r][c] # idem
    # 2/3 - maximize cols
    #   - we need as many 1s as possible
    cols = [0] * C
    for r in range(R):
        for c in range(C):
            cols[c] += G[r][c]
    for c in range(C):
        cols[c] = max(cols[c], R - cols[c])
    # 3/3 - then its just math
    res = 0
    for col in cols:
        res = res * 2 + col
    return res
