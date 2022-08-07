class Solution {
using vvi = vector<vector<int>>;
public:
    void gameOfLife(vector<vector<int>>& board)
    {
        int c = board[0].size();
        int r = board.size();
        int i, j;

        i = -1;
        while (++i < r)
        {
            j = -1;
            while (++j < c)
            {
                int alive = countNeighbors(board, r, c, i, j);
                int state = board[i][j];
                if ((alive < 2 || alive > 3) && state == 1)
                    board[i][j] = 2;
                else if (alive == 3 && state == 0)
                    board[i][j] = -1;
            }
        }
        i = -1;
        while (++i < r)
        {
            j = -1;
            while (++j < c)
            {
                int state = board[i][j];
                if (state == 2)
                    board[i][j] = 0;
                else if (state == -1)
                    board[i][j] = 1;
            }
        }
    }

    int countNeighbors(vvi board, int r, int c, int x, int y)
    {
        int dx, dy, i, j;
        int count = 0;
        dx = -2;
        while (++dx < 2)
        {
            dy = -2;
            while (++dy < 2)
            {
                if (!dx && !dy)
                    continue;
                i = x + dx;
                j = y + dy;
                if (i > -1 && i < r && j > -1 && j < c && board[i][j] > 0)
                    ++count;
            }
        }
        return count ;
    }
};
