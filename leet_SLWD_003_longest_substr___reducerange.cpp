class Solution {
public:
    int lengthOfLongestSubstring(string s)
    {
        int len = (int) s.length();

        if (len < 2)
            return len;

        set<char>   E;
        int         i, L, R, res;

        //  reduce search length in case ending chars are repeated

        i = len - 1;
        while (i - 1 > -1 && s[i - 1] == s[i])
            --i;
        len = i + 1;

        //  same action for leading chars

        i = 0;
        while (i + 1 < len && s[i + 1] == s[i])
            ++i;
        R = i - 1;
        L = i;

        //  apply sliding window within above range

        res = 0;
        while (++R < len)
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
