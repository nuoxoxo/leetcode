class Solution {
public:
    int findLength(vector<int>& n1, vector<int>& n2)
    {
        int         s1 = n1.size();
        int         s2 = n2.size();
        vector<vector<int>> dp(s1 + 1, vector<int>(s2 + 1, 0));
        int         res = 0, i = 0, j;

        while (++i < s1 + 1)
        {
            j = 0;
            while (++j < s2 + 1)
            {
                if (n1[i - 1] == n2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    res = max(res, dp[i][j]);
                }
                else
                {
                    dp[i][j] = 0;
                }
            }
        }
        return res;
    }
};
