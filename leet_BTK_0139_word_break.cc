class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict)
    {
        vector<bool(*)(string, vector<string>&)> Solutions {
            Backtracking,
        };
        return Solutions[0](s, wordDict);
    }

    static bool Backtracking(string s, vector<string>& wordDict)
    {
        int N = s.length();
        unordered_map<int, bool> memo;

        std::function<bool(int)> possible = [&](int pos) {
            if (pos ==  N)
                return true;
            if (memo.find(pos) != memo.end())
                return memo[pos];
            // has_memo[pos] = true;
            for (string w : wordDict)
            {
                int len = w.length();
                if (s.substr(pos, len) == w)
                {
                    if ( possible(pos + len) )
                    {
                        memo[pos] = true;
                        return true;
                    }
                }
            }
            memo[pos] = false;
            return false;
        };
        return possible(0);
    }
};
