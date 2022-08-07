class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& env)
    {
        int res = 0, n = env.size(), i, j;
        vector<int> dp(n, 1);

        sort(env.begin(), env.end());
        i = -1;
        while (++i < n)
        {
            j = -1;
            while (++j < i)
            {
                if (env[i][0] > env[j][0] && env[i][1] > env[j][1])
                    dp[i] = max(dp[i], dp[j] + 1);
            }
            res = max(res, dp[i]);
        }
        return res;
    }
};
