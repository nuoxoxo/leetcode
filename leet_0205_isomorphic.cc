class Solution {
public:
    bool isIsomorphic(string s, string t)
    {
        int N = s.length();
        if (N != t.length())
            return false;
        int s2t[128];
        bool checked[128];
        int i = -1;
        while (++i < N)
        {
            if (s2t[s[i]] && s2t[s[i]] != t[i])
                return false;
            if (!s2t[s[i]] && checked[t[i]])
                return false;
            s2t[s[i]] = t[i];
            checked[t[i]] = true;
        }
        return true;
    }
};
