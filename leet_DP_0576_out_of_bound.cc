class Solution {
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<int(*)(int,int,int,int,int)> Solutions {
            DP_iterative_tabulation,
        };
        return Solutions[ 0 ]( m, n, maxMove, startRow, startColumn );
    }
    static int DP_iterative_tabulation (
        int m, int n, int maxMove, int startRow, int startColumn
    ) {

        cout << "/DP_iterative_tabulation\n";

        vector<vector<int>> dp(m, vector<int>(n, 0));
        int MOD = 1e9 + 7;
        vector<vector<int>> cp(dp);
        int i = -1;
        vector<int> DR = {-1, 0, 1, 0};
        vector<int> DC = { 0, 1, 0,-1};
        while (++i < maxMove) {
            int r = -1;
            while (++r < m) {
                int c = -1;
                while (++c < n) {
                    long long tt = 0;
                    int d = -1;
                    while (++d < 4) {
                        int rr = r + DR[d];
                        int cc = c + DC[d];
                        if ( ! (rr < m && rr > -1 && cc < n && cc > -1)) {
                            tt++;
                            tt %= MOD;
                        } else {
                            tt += (dp[rr][cc] % MOD);
                        }
                    }
                    cp[r][c] = tt % MOD;
                }
            }
            dp = cp;
        }
        return dp[ startRow ][ startColumn ];
    }
};
