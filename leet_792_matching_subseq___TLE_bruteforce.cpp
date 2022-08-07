class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words)
    {
        set<string>     S;
        int             res = 0;

        sort(words.begin(), words.end());
        for (string w: words)
        {
            if (S.find(w) != S.end())
                res += 1;
            else if (is_subseq(s, w))
            {
                S.insert(w);
                res += 1;
            }
        }
        return res;
    }

    int is_subseq(string s, string tocheck)
    {
        int     i, j, ls, lt;

        lt = tocheck.length();
        ls = s.length();
        if (lt > ls)
            return 0;
        i = 0;
        j = 0;
        while (i < ls && j < lt)
        {
            if (s[i] == tocheck[j])
            {
                i += 1;
                j += 1;
            }
            else
                i += 1;
            if (i == ls && j == lt)
                break ;
            if (i == ls)
                return 0;
        }
        return 1;
    }
};
