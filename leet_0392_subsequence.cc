class Solution {
public:
    bool isSubsequence(string s, string t)
    {
        if (s == "")
            return true;
        int S = s.length();
        int T = t.length();
        int i = 0, j = 0;
        while (i < S && j < T)
        {
            if (s[i] == t[j])
            {
                ++i;
            }
            ++j;
            if (i == S)
                return true;
        }
        return false;
    }
};
