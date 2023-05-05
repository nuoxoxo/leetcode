class Solution {
public:
    void solveSudoku(vector<vector<char>>& board)
    {
        vector<int> move = next_move(board);

        if (move[0] == -1)
            return ;

        int i = 0; // guess
        int r = move[0];
        int c = move[1];

        // cout << r << ' ' << c << '\n';

        while (++i < 10)
        {
            if (is_legal(board, i, r, c))
            {
                board[r][c] = (char) (i + '0');
                solveSudoku(board);
                if (next_move(board)[0] < 0)
                    return ;
                board[r][c] = '.';
            }
            
        }
    }

    // help

    vector<int> next_move(vector<vector<char>> & g)
    {
        int r = -1, c;
        while (++r < 9)
        {
            c = -1;
            while (++c < 9)
            {
                if (g[r][c] == '.')
                    return {r, c};
            }
        }
        return {-1, -1};
    }

    int is_legal(vector<vector<char>> & g, int guess, int r, int c)
    {
        // check row
        if (find(g[r].begin(), g[r].end(), (char) (guess + '0')) != g[r].end())
            return 0;
        // check col
        vector<int> C;
        int i = -1;
        while (++i < 9)
            C.push_back(g[i][c]);
        if (find(C.begin(), C.end(), (char) (guess + '0')) != C.end())
            return 0;
        // check 3x3 grid
        // int r0 = (int) (((float) r / 3) * 3);
        // int c0 = (int) (((float) c / 3) * 3);
        int r0 = (r / 3) * 3;
        int c0 = (c / 3) * 3;
        int rr = r0 - 1, cc;
        while (++rr < r0 + 3)
        {
            cc = c0 - 1;
            while (++cc < c0 + 3)
                if (g[rr][cc] == (char) (guess + '0'))
                    return 0;
        }
        return 1;
    }
};
