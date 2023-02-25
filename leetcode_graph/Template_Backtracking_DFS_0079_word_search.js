var exist = function(board, word) {
    let i = -1
    while (++i < board.length) {
        let j = -1
        while (++j < board[0].length) {
            if (dfs(board, word, 0, i, j))
                return true
        }
    }
    return false
};

var dfs = function(board, word, index, x, y) {
    if (index == word.length)
        return true
    let c = board[0].length
    let r = board.length
    if (x < 0 || y < 0 || x > r - 1 || y > c - 1 || board[x][y] != word[index])
        return false
    board[x][y] = '#'
    let isFound = (
        dfs(board, word, index + 1, x + 1, y) ||
        dfs(board, word, index + 1, x - 1, y) ||
        dfs(board, word, index + 1, x, y + 1) ||
        dfs(board, word, index + 1, x, y - 1)
    )
    board[x][y] = word[index]
    return isFound
}
