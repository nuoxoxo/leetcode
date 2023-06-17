class Solution:
    def numRookCaptures(self, board: List[List[str]]) -> int:
        res = 0
        R = len(board)
        C = len(board[0])
        found = False
        r = -1

        for r in range(R):
            for c in range(C):
                if board[r][c] == 'R':
                    found = True
                    break
            if found:
                break

        # L R
        i = r
        while i > -1:
            if board[i][c] == 'B':
                break
            if board[i][c] == 'p':
                res += 1
                break
            i -= 1

        i = r
        while i < R:
            if board[i][c] == 'B':
                break
            if board[i][c] == 'p':
                res += 1
                break
            i += 1

        # U D
        i = c
        while i > -1:
            if board[r][i] == 'B':
                break
            if board[r][i] == 'p':
                res += 1
                break
            i -= 1

        i = c
        while i < C:
            if board[r][i] == 'B':
                break
            if board[r][i] == 'p':
                res += 1
                break
            i += 1

        return res
