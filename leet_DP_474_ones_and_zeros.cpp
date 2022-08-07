class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n)
    {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        int                 zeros, ones, i, j;

        for (string& s: strs)
        {
            zeros = count(s.begin(), s.end(), '0');
            ones = s.length() - zeros;

            i = m + 1;
            while (--i > zeros - 1)
            {
                j = n + 1;
                while (--j > ones - 1)
                    dp[i][j] = max(dp[i][j], 1 + dp[i - zeros][j - ones]);
            }
        }
        return dp[m][n];
    }
};
