class Solution {
public:
    int longestStrChain(vector<string>& words)
    {
        unordered_map<string, int>  dp;
        int res = 1;
        sort(words.begin(), words.end(), [](string & a, string & b){
            return a.length() < b.length();
        });
        for (string & w: words)
        {
            int i = -1;
            while (++i < w.length())
            {
                string s = w.substr(0, i) + w.substr(i + 1);
                cout << s << endl;
                dp[w] = max(dp[w], dp[s] + 1);
            }
            res = max(res, dp[w]);
        }
        return res;
    }
};
