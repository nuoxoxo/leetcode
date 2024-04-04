class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:

        R, C = len(board), len(board[0])
        N = len(word)
        dr, dc = [-1, 1, 0, 0], [0, 0, -1, 1]
        seen = [[False for _ in range(C)] for _ in range(R)]

        def dfs(g, r, c, s, idx, seen) -> bool:
            if idx > N - 1:
                return True
            if not (-1 < r < R and -1 < c < C and not seen [r][c] and g[r][c] == s[idx]):
                return False
            seen[r][c] = True
            for i in range(4):
                rr, cc = r + dr[i], c + dc[i]
                if dfs(g, rr, cc, s, idx + 1, seen):
                    return True
            seen[r][c] = False
            return False
        for r in range(R):
            for c in range(C):
                if dfs(board, r, c, word, 0, seen):
                    return True
        return False
