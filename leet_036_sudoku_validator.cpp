class Solution {
public:
    bool    isValidSudoku(vector<vector<char>>& board)
    {
        int     x = -1, y;
        
        while (++x < 9)
        {
            y = -1;
            while (++y < 9) if (board[x][y] != '.' && (!check_row(board, x, y)
            || !check_col(board, x, y) || !check_box(board, x, y))) return (false);
        }
        return (true);
    }
    
    bool    check_row(vector<vector<char>>& board, int x, int y)
    {
        int     i = -1;
        
        while (++i < 9) if (i != x && board[x][y] == board[i][y])   return (false);
        return (true);
    }
    
    bool    check_col(vector<vector<char>>& board, int x, int y)
    {
        int     i = -1;
        
        while (++i < 9) if (i != y && board[x][y] == board[x][i])   return (false);
        return (true);
    }
    
    bool    check_box(vector<vector<char>>& board, int x, int y)
    {
        int     xo, yo, i, j;

        xo = x / 3 * 3;
        yo = y / 3 * 3;
        i = xo - 1;
        while (++i < xo + 3)
        {
            j = yo - 1;
            while (++j < yo + 3)
                if (board[i][j] == board[x][y] && x != i && y != j) return (false);
        }
        return (true);
    }
};
