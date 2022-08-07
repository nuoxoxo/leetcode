class Solution {
public:
    bool isAnagram(string s, string t)
    {
        map<int, int>   mps;
        map<int, int>   mpt;
        int             len, i;

        len = s.length();
        if (len != t.length())
            return (false);
        i = -1;
        while (++i < len)
        {
            mps[s[i]]++;
            mpt[t[i]]++;
        }
        return (equal(mps.begin(), mps.end(), mpt.begin()));
    }
};
