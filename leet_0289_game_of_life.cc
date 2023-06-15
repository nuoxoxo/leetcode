class Solution {
using vvi = vector<vector<int>>;
public:
    void gameOfLife(vector<vector<int>>& board)
    {
        int c = board[0].size();
        int r = board.size();
        int i, j;
        vvi v = board;

        i = -1;
        while (++i < r)
        {
            j = -1;
            while (++j < c)
            {
                int temp = countNeighbors(board, r, c, i, j);
                if (temp < 2 && board[i][j] == 1)
                    v[i][j] = 0;
                else if (temp > 3 && board[i][j] == 1)
                    v[i][j] = 0;
                else if (temp == 3 && board[i][j] == 0)
                    v[i][j] = 1;
            }
        }
        board = v;
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
                if (i > -1 && i < r && j > -1 && j < c && board[i][j])
                    ++count;
            }
        }
        return count ;
    }
};
