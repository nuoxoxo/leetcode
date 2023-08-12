class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& g /*obstacleGrid*/) {
        int R = (int) g.size();
        int C = (int) g[0].size();
        vector<vector<int>> DP(R + 1, vector<int>(C + 1, 0));
        DP[0][1] = 1;
        int i = 0, j;
        while (++i < R + 1)
        {
            j = 0;
            while (++j < C + 1)
            {
                if (g[i - 1][j - 1] == 0)
                    DP[i][j] = DP[i - 1][j] + DP[i][j - 1];
            }
        }
        return DP[R][C];
    }
};


