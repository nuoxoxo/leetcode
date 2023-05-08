class Solution:
    def checkXMatrix(self, g: List[List[int]]) -> bool:
        S = len(g)
        for r in range(S):
            for c in range(S):
                if (r == c or c == S - r - 1) and g[r][c] == 0:
                    return False
                elif r ^ c and c ^ S - r - 1 and g[r][c] != 0:
                    return False
        return True

