class Solution {
public:
    bool isIsomorphic(string s, string t)
    {
        map<char, char> e;
        char            c;
        int             i, ls, lt;

        ls = s.length();
        lt = t.length();
        if (ls - lt)
            return (false);
        i = -1;
        while (++i < ls)
        {
            c = s[i];
            if (e.find(c) == e.end())
            {
                e[c] = t[i];
            }
            else
            {
                if (e[c] != t[i])
                {
                    return (false);
                }
            }
        }
        return (true);
    }
};
