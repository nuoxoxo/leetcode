class Solution:
    def solveNQueens(self, n: int) -> int:
        board = ['.' * n for _ in range(n)]
        # print(board)
        self.res = []
        self.backtrack(board, 0)
        return self.res
    def backtrack(self, b, r):
        n = len(b)
        if r == n:
            # self.res.append(b)
            self.res.append(b.copy())
            return
        for i in range(n):
            if self.checkdiag(b, r, i) and self.checkleft(b, r, i):
                # temp = list(b[r])
                # temp[i] = 'Q'
                # b[r] = ''.join(temp)
                
                b[r] = b[r][:i] + 'Q' + b[r][i + 1:]
                
                self.backtrack(b, r + 1)
                
                b[r] = b[r][:i] + '.' + b[r][i + 1:]
                
                # temp = list(b[r])
                # temp[i] = '.'
                # b[r] = ''.join(temp)
    def checkdiag(self, b, r, c):
        i = r - 1
        j = c - 1
        while i > -1 and j > -1:
            if b[i][j] == 'Q':
                return False
            i -= 1
            j -= 1
        i = r - 1
        j = c + 1
        while i > -1 and j < len(b):
            if b[i][j] == 'Q':
                return False
            i -= 1
            j += 1
        return True
    def checkleft(self, b, r, c):
        i = r - 1
        while i > -1:
            if b[i][c] == 'Q':
                return False
            i -= 1
        return True
        
