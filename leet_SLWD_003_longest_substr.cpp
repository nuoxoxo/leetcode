class Solution {
public:
    int lengthOfLongestSubstring(string s)
    {
        set<char>   E;
        int res = 0, L = 0, R = -1, n = (int) s.length();
        while (++R < n)
        {
            while (E.find(s[R]) != E.end())
            {
                E.erase(s[L]);
                ++L;
            }
            E.insert(s[R]);
            res = max(res, R - L + 1);
        }
        return res;
    }
};
