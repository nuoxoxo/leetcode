class Solution {
public:
    char findTheDifference(string s, string t)
    {
        int res = t[t.length() - 1];
        int i = -1;
        while (++i < s.length())
        {
            res += t[i];
            res -= s[i];
        }
        return (char) res ;
    }
};
