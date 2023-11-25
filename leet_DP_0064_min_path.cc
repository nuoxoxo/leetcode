class Solution {
public:
    int minPathSum(vector<vector<int>>& grid)
    {
        int R = (int) grid.size();
        int C = (int) grid[0].size();
        vector<vector<int>> DP(R, vector<int>(C, 0));
        DP[0][0] = grid[0][0];
        int i = 0, j;
        while (++i < R)
            DP[i][0] = DP[i - 1][0] + grid[i][0];
        i = 0;
        while (++i < C)
            DP[0][i] = DP[0][i - 1] + grid[0][i];
        i = 0;
        while (++i < R)
        {
            j = 0;
            while (++j < C)
                DP[i][j] = min(DP[i - 1][j], DP[i][j - 1]) + grid[i][j];
        }
        return DP[R - 1][C - 1];
    }
};
