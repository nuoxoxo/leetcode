class Solution {
public:
    int checkRecord(int N)
    {
        vector<vector<vector<int>>> cache(N, vector<vector<int>>(2, vector<int>(3, 0)));
        vector<vector<vector<bool>>> hasCache(N, vector<vector<bool>>(2, vector<bool>(3, false)));

        int MOD = int(1e9 + 7);

        function<int(int, int, int)> DFS = [&](int days, int A, int L)
        {
            // base and caching
            if (days == N)
            return 1;
            if (hasCache[days][A][L]) return cache[days][A][L];

            int res = 0;

            // present - nothing happens
            res += DFS(days + 1, A, 0);
            res %= MOD;

            // absent - add to A where max(A) == 1
            if (A == 0) {
                res += DFS(days + 1, A + 1, 0);
                res %= MOD;
            }

            // late - add to consecutive L where max(L) == 2
            if (L < 2) {
                res += DFS(days + 1, A, L + 1);
                res %= MOD;
            }

            cache[days][A][L] = res;
            hasCache[days][A][L] = true;

            return res;
        };

        return DFS(0, 0, 0);
    }
};
