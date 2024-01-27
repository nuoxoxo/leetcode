class Solution {
public:

    using ll = long long;

    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<int(*)(int,int,int,int,int)> Solutions {
            DP_iterative_tabulation,
            // DP_recursive_cached_count,
        };
        return Solutions[ 0 ]( m, n, maxMove, startRow, startColumn );
    }

    static int DP_recursive_cached_count(
        int m, int n, int maxMove, int startRow, int startColumn
    ) {
        cout << "/DP_recursive_cached_count using DIY caching" << endl;
        ll MOD = 1e9 + 7;
        vector<int> DR = {-1, 0, 1, 0};
        vector<int> DC = {0, -1, 0, 1};

        vector<vector<vector<bool>>> has_cache(m, vector<vector<bool>>(n, vector<bool>(maxMove + 1, false)));
        vector<vector<vector<ll>>> cache(m, vector<vector<ll>>(n, vector<ll>(maxMove + 1, 0)));

        function< int (int, int, ll)> DP = [&](int r, int c, ll moves) -> int {
            ll res = 0;
            if (!(r >= 0 && r < m) || !(c >= 0 && c < n)) {
                return 1;
            } else if (moves == maxMove) {
                return 0;
            }

            if (has_cache[r][c][moves]) {
                return cache[r][c][moves];
            }

            for (int i = 0; i < 4; ++i) {
                int dr = DR[i];
                int dc = DC[i];
                res += DP(r + dr, c + dc, moves + 1);
            }

            has_cache[r][c][moves] = true;
            cache[r][c][moves] = res % MOD;
            return (int)(res % MOD);
        };

        return (int)(DP(startRow, startColumn, 0) % MOD);
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
