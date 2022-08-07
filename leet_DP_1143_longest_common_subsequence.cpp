class Solution {
public:
    int longestCommonSubsequence(string s1, string s2)
    {
        int                 len1 = s1.length(), len2 = s2.length();
        vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));
        int                 i = 0, j = 0;
        while (++i < len1 + 1)
        {
            j = 0;
            while (++j < len2 + 1)
            {
                if (s1[i - 1] == s2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[len1][len2];
    }
};
