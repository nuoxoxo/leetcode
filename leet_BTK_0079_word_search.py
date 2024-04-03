class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        for x in range(len(board)):
            for y in range(len(board[0])):
                if self.DFS(board, word, 0, x, y):
                    return True
        return False
    def DFS(self, board: List[List[str]], word:str, i: int, x: int, y: int) -> bool:
        if i == len(word):
            return True
        if x < 0 or y < 0 or x > len(board) - 1 or y > len(board[0]) - 1 or word[i] != board[x][y] :
            return False
        board[x][y] = chr(0)
        found = (
            self.DFS(board, word, i + 1, x + 1, y) or
            self.DFS(board, word, i + 1, x - 1, y) or
            self.DFS(board, word, i + 1, x, y + 1) or
            self.DFS(board, word, i + 1, x, y - 1))
        board[x][y] = word[i]
        return found
