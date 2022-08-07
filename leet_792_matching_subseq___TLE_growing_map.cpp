class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words)
    {
        map<string, int>    seen;
        int                 res, i;

        res = 0;
        for (string w: words)
        {
            if (seen[w])
            {
                res += seen[w];
                continue ;
            }
            i = 0;
            seen[w] = 0;
            for (char c: s)
            {
                if (c == w[i])
                    i += 1;
                if (i == w.length())
                {
                    res += 1;
                    seen[w] = 1;
                    break ;
                }
            }
        }
        return res;
    }
};
