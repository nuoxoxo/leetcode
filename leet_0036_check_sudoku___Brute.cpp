class Solution {
public:

    bool isValidSudoku(vector<vector<char>>& board)
    {
        vector<int>     d;
        int             r, c, rr, cc;
        int             n;

        for (vector<char> R: board)
        {
            d = {};
            for (char c: R)
            {
                if (!isdot(c))
                {
                    if (find(d.begin(), d.end(), c) != d.end())
                    {
                        // cout << "1" << endl;
                        return false;
                    }
                    d.push_back(c);
                }
            }
        }
        c = -1;
        while (++c < 9)
        {
            d = {};
            r = -1;
            while (++r < 9)
            {
                n = board[r][c];
                if (!isdot(n))
                {
                    if (find(d.begin(), d.end(), n) != d.end())
                    {
                        // cout << "2" << endl;
                        return false;
                    }
                    d.push_back(n);
                }
            }
        }
        r = -1;
        while (++r < 3)
        {
            c = -1;
            while (++c < 3)
            {
                d = {};
                rr = r * 3 - 1;
                while (++rr < r * 3 + 3)
                {
                    cc = c * 3 - 1;
                    while (++cc < c * 3 + 3)
                    {
                        n = board[rr][cc];
                        if (!isdot(n))
                        {
                            if (find(d.begin(), d.end(), n) != d.end())
                            {
                                // cout << "3" << endl;
                                return false;
                            }
                            d.push_back(n);
                        }
                    }
                }
            }
        }
        return true;
    }

    int      isdot(char c) { return (c == '.'); }
};

/*
[[".",".","4",".",".",".","6","3","."],[".",".",".",".",".",".",".",".","."],["5",".",".",".",".",".",".","9","."],[".",".",".","5","6",".",".",".","."],["4",".","3",".",".",".",".",".","1"],[".",".",".","7",".",".",".",".","."],[".",".",".","5",".",".",".",".","."],[".",".",".",".",".",".",".",".","."],[".",".",".",".",".",".",".",".","."]]
*/
