class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words)
    {
        map<string, int>    seen;
        int                 res, ls, lw, i, j;

        for (string w: words)
        {
            seen[w] += 1;
        }
        words.clear();
        for (pair p: seen)
        {
            words.push_back(p.first);
        }
        res = 0;
        ls = s.length();
        for (string w: words)
        {
            lw = w.length();
            i = 0;
            j = 0;
            while (i < ls && j < lw)
            {
                if (s[i] == w[j])
                    j++;
                i++;
            }
            if (j == lw)
                res += seen[w];
        }
        return res;
    }
};
