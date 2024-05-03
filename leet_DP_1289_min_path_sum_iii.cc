class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid)
    {
        /*
        15 - 157,159
        16 - 167,168
        24 - 248,249
        26 - 267,268
        34 - 348,349
        35 - 357,359
        */

        vector<int(*)(vector<vector<int>> &)> Solutions
        {
            // nCubed,
            Tracking_min_and_2nd_min,
        };
        return Solutions[0](grid);
    }

    static int Tracking_min_and_2nd_min(vector<vector<int>>& G)
    {

        long long INF = 2147483648;
        int N = G.size();
        int R = N, C = N;
        vector<vector<long long>> dp(R, vector<long long>(C, INF));
        int c = -1;
        while (++c < C) {
            dp[0][c] = G[0][c];
        }
        int r = 0;
        while (++r < R) {
            long long min_val = INF, second_min_val = INF;
            int min_idx = -1;
            c = -1;
            while (++c < C) {
                if (dp[r - 1][c] < min_val) {
                    // branched out (1) - upd. min val if a smaller one is found
                    second_min_val = min_val;
                    min_val = dp[r - 1][c];
                    min_idx = c;
                } else if (dp[r - 1][c] < second_min_val) {
                    // branched out (2) - when `min_val < PreviousRow[c] < second_min_val`
                    second_min_val = dp[r - 1][c];
                }
            }
            c = -1;
            while (++c < C) {
                if (c ^ min_idx)
                    dp[r][c] = G[r][c] + min_val;
                else
                    dp[r][c] = G[r][c] + second_min_val;
            }
        }
        return (int) *std::min_element(dp[N - 1].begin(), dp[N - 1].end());
    }

    static int nCubed(vector<vector<int>>& G)
    {

        long long INF = 2147483648;
        int N = G.size();
        int R = N, C = N;
        vector<vector<long long>> dp(R, vector<long long>(C, INF));
        int c = -1;
        while (++c < C) {
            dp[0][c] = G[0][c];
        }
        int r = 0;
        while (++r < R) {
            c = -1;
            while (++c < C) {
                int idx = -1;
                while (++idx < C) {
                    if (idx == c)
                        continue ;
                    long long temp = dp[r - 1][idx] + G[r][c];
                    dp[r][c] = min(dp[r][c], temp);
                }
            }
        }
        return (int)*std::min_element(dp[N - 1].begin(), dp[N - 1].end());
    }
};
