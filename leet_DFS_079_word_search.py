class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        for x in range(len(board)):
            for y in range(len(board[0])):
                if self.DFS(board, word, 0, x, y):
                    return True
        return False

    def DFS(self, board: List[List[str]], word:str, index: int, x: int, y: int) -> bool:
        if index == len(word):
            return True
        c = len(board[0])
        r = len(board)
        if x < 0 or y < 0 or x > r - 1 or y > c - 1 or word[index] != board[x][y] :
            return False
        board[x][y] = chr(0)
        found = (
            self.DFS(board, word, index + 1, x + 1, y) or
            self.DFS(board, word, index + 1, x - 1, y) or
            self.DFS(board, word, index + 1, x, y + 1) or
            self.DFS(board, word, index + 1, x, y - 1))
        board[x][y] = word[index]
        return found
        
