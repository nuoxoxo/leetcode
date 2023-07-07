class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& g)
    {
        int R = (int) g.size() - 2;
        int C = (int) g[0].size() - 2;
        vector<vector<int>> res = vector<vector<int>>(R, vector<int>(C, 0));
        int r = -1, c;
        while (++r < R)
        {
            c = -1;
            while (++c < C)
                res[r][c] = Max_Local(g, r, c);
        }
        return res;
    }

    int Max_Local(vector<vector<int>>& g, int r, int c)
    {
        int res = -1;
        int rr = r - 1;
        int cc;
        while (++rr < r + 3)
        {
            cc = c - 1;
            while (++cc < c + 3)
            {
                int val = g[rr][cc];
                res = max(res, val);
            }
        }
        return res;
    }
};
