class Solution {
public:
    int longestStrChain(vector<string>& arr)
    {
        map<string, int>    dp;
        int res = 1;

        sort(arr.begin(), arr.end(), [](string &s1, string &s2){
            return s1.length() < s2.length();
        });

        for (string s: arr)
        {
            int i = -1;
            while (++i < s.length())
            {
                string  tmp = s;
                tmp.erase(i, 1);
                dp[s] = max(dp[tmp] + 1, dp[s]);
            }
            res = max(res, dp[s]);
        }
        return res;
    }
};
