class   Solution
{

private:
    int     rows, cols;

public:
    bool    exist(vector<vector<char>>& board, string word)
    {
            rows = (int) board.size();
            cols = (int) board[0].size();
            if (!board.size()) return (false);
            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < cols; j++)
                    if (dfs(board, word, 0, i, j))  return (true);
            }
            return (false);
    }

    bool    dfs(vector<vector<char>> &board, string &word, int i, int x, int y)
    {
        bool    found;
        char    temp;

        if (x < 0 || x == rows || y < 0 || y == cols || word[i] != board[x][y])
            return (false);
        if (i == (int) word.length() - 1)
            return (true);
        temp = board[x][y];
        board[x][y] = 0;
        found = dfs(board, word, i + 1, x + 1, y) ||
                dfs(board, word, i + 1, x - 1, y) ||
                dfs(board, word, i + 1, x, y + 1) ||
                dfs(board, word, i + 1, x, y - 1);
        board[x][y] = temp;
        return (found);
    }
};
