class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board)
    {
        int res = 0;
        int R = (int) board.size();
        int C = (int) board[0].size();
        int r = -1, c, i;
        int found = false;
        while (++r < R)
        {
            c = -1;
            while (++c < C)
            {
                if (board[r][c] == 'R')
                {
                    found = true ;
                    break ;
                }
            }
            if (found)
                break ;
        }
        cout << r << ' ' << c << '\n';
        // L R
        i = r;
        while (--i > -1)
        {
            if (board[i][c] == 'B')
                break ;
            if (board[i][c] == 'p')
            {
                ++res;
                break ;
            }
        }
        i = r;
        while (++i < R)
        {
            if (board[i][c] == 'B')
                break ;
            if (board[i][c] == 'p')
            {
                ++res;
                break ;
            }
        }

        // U D
        i = c;
        while (--i > - 1)
        {
            if (board[r][i] == 'B')
                break ;
            if (board[r][i] == 'p')
            {
                ++res;
                break ;
            }
        }
        i = c;
        while (++i < C)
        {
            if (board[r][i] == 'B')
                break ;
            if (board[r][i] == 'p')
            {
                ++res;
                break ;
            }
        }
        return res;
    }
};
