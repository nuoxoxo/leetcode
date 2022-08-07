class Solution {
public:
    int minDistance(string s1, string s2)
    {
        int                 n1 = s1.length(), n2 = s2.length(), i = 0, j;
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));

        while (++i < n1 + 1)
        {
            j = 0;
            while (++j < n2 + 1)
            {
                if (s1[i - 1] != s2[j - 1])
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                else
                    dp[i][j] = 1 + dp[i - 1][j - 1];
            }
        }
        return (n1 + n2 - 2 * dp[n1][n2]);
    }
};
