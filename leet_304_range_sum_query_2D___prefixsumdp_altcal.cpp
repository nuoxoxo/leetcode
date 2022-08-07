class NumMatrix {
public:
    
    vector<vector<int>> g;
    
    NumMatrix(vector<vector<int>>& m)
    {
        int r, c, i;
        r = (int) m.size();
        c = (int) m[0].size();
        g.clear();
        g = vector<vector<int>>(r + 1, vector<int>(c + 1, 0));
        i = -1;
        while (++i < r)
        {
            // int prefix = 0;
            int j = -1;
            while (++j < c)
            {
                int U = g[i][j + 1];
                int L = g[i + 1][j];
                int UL = g[i][j];
                g[i + 1][j + 1] = m[i][j] + U + L - UL;
            }
        }
    }
    
    int sumRegion(int r1, int c1, int r2, int c2)
    {
        if (g.empty())
            return 0;
        int self = g[r1][c1];
        int U = g[r1][c2 + 1];
        int L = g[r2 + 1][c1];
        int DR = g[r2 + 1][c2 + 1];
        // cout << self << ' ' << U << ' ' << L << ' ' << DR << endl;
        return self - U - L + DR;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
