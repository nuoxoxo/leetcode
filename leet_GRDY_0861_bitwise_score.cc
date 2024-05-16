class Solution {
public:
    #define vvi vector<vector<int>>
    int matrixScore(vector<vector<int>>& grid)
    {
        vector<int(*)(vvi&)> solutions {
            greedy_cols_dp,
        };
        return solutions[0](grid);
    }

    static int greedy_cols_dp(vvi& G)
    {
        int R = G.size();
        int C = G[0].size();
        int r, c;

        r = -1;
        //  1/3 - max the rows :
        //      the most significant has to be 1
        while (++r < R)
        {
            if (G[r][0] == 0)
            {
                c = -1;
                while (++c < C)
                    G[r][c] = 1 - G[r][c];
            }
        }
        //  2/3 - max the cols :
        //      as many 1s as possible
        vector<int> cols(C, 0);
        r = -1;
        while (++r < R)
        {
            c = -1;
            while (++c < C)
                cols[c] += G[r][c];
        }
        c = -1;
        while (++c < C)
            if (cols[c] < R - cols[c])
                cols[c] = R - cols[c];
        int res = 0;
        c = -1;
        while (++c < C)
            res = res * 2 + cols[c];
        return res;
    }

};
