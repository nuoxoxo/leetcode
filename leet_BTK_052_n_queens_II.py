class Solution:
    def totalNQueens(self, n: int) -> int:
        board = [[False] * n for _ in range(n)]
        # print(board)
        self.res = 0
        self.backtrack(board, 0)
        return self.res
    def backtrack(self, b, r):
        n = len(b)
        if r == n:
            self.res += 1
            return
        for i in range(n):
            if self.checkdiag(b, r, i) and self.checkleft(b, r, i):
                b[r][i] = True
                self.backtrack(b, r + 1)
                b[r][i] = False
    def checkdiag(self, b, r, c):
        i = r - 1
        j = c - 1
        while i > -1 and j > -1:
            if b[i][j]:
                return False
            i -= 1
            j -= 1
        i = r - 1
        j = c + 1
        while i > -1 and j < len(b):
            if b[i][j]:
                return False
            i -= 1
            j += 1
        return True
    def checkleft(self, b, r, c):
        i = r - 1
        while i > -1:
            if b[i][c]:
                return False
            i -= 1
        return True
        
