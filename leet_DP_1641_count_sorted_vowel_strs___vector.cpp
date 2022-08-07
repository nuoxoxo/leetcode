class Solution {
public:
    int countVowelStrings(int n)
    {
        vector<int> dp(5, 1);
        int         res = 0;

        while (--n)
        {
            int i = 4;
            while (--i > -1)
                dp[i] += dp[i + 1];
        }
        return accumulate(dp.begin(), dp.end(), 0);
    }

};
