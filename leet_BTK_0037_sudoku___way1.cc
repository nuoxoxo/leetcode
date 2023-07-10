class Solution {
public:
    void solveSudoku(vector<vector<char>>& board)
    {
        solver(board);
    }


    // solver

    int solver(vector<vector<char>> & G)
    {
        vector<int> move = next_move(G);

        if (move[0] == -1)
            return 1;

        int i = 0; // guess
        int r = move[0];
        int c = move[1];

        cout << r << ' ' << c << '\n';

        while (++i < 10)
        {
            if (is_legal(G, i, r, c))
            {
                G[r][c] = (char) (i + '0');
                if (solver(G))
                    return 1;
            }
            G[r][c] = '.';
        }
        return 0;
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
