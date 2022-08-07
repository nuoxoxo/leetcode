class Solution {
public:
    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>>  res;
        vector<string>          b(n, string(n, '.'));
        backtracking(res, b, 0);
        return res;
    }

    void    backtracking(vector<vector<string>>& res, vector<string>& b, int r)
    {
        int n = b.size();
        if (r == n)
        {
            res.push_back(b);
            return;
        }
        int i = -1;
        while (++i < n)
        {
            if (checkDiag(b, r, i) && checkLeft(b, r, i))
            {
                b[r][i] = 'Q';
                backtracking(res, b, r + 1);
                b[r][i] = '.';
            }
        }
    }

    bool    checkDiag(vector<string>& b, int r, int c)
    {
        int i = r, j = c;
        while (--i > -1 && --j > -1)
            if (b[i][j] == 'Q')
                return false;
        i = r;
        j = c;
        while (--i > -1 && ++j < (int) b.size())
            if (b[i][j] == 'Q')
                return false;
        return true;
    }

    bool    checkLeft(vector<string>& b, int r, int c)
    {
        int i = r;
        while (--i > -1)
            if (b[i][c] == 'Q')
                return false;
        return true;
    }
};
