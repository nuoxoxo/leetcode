class Solution:
    def solveSudoku(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        def is_legal(G: List[List[str]], guess: int, r: int, c: int) -> bool:
            if str(guess) in G[r]:
                return False
            # print([_[c] for _ in G])
            if str(guess) in [_[c] for _ in G]:
                return False
            r0 = r // 3 * 3
            c0 = c // 3 * 3
            rr = r0
            while rr < r0 + 3:
                cc = c0
                while cc < c0 + 3:
                    if G[rr][cc] == str(guess):
                        return False
                    cc += 1
                rr += 1
            return True
        def next_move(G: List[List[str]]) -> List[int]:
            for r in range(9):
                for c in range(9):
                    if G[r][c] == '.':
                        return [r, c]
            return [-1, -1]
        # solver proper
        r, c = next_move(board)
        if r == -1:
            return
        print(r, c)
        for guess in range(1, 10):
            if is_legal(board, guess, r, c):
                board[r][c] = str(guess)
                self.solveSudoku(board)
                if next_move(board)[0] == -1:
                    return
                board[r][c] = '.'
                    

