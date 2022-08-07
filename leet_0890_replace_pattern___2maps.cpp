class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern)
    {
        vector<string>      res;

        for (string w: words)
        {
            if (valid(w, pattern))
                res.push_back(w);
        }
        return res;
    }

    bool    valid(string w, string p)
    {
        vector<char>    from_word(26, -1);
        vector<char>    from_patt(26, -1);
        char            cw, cp;
        int             len, i;

        len = w.length();
        i = -1;
        while (++i < len)
        {
            cw = w[i];
            cp = p[i];
            if (from_word[cw - 'a'] < 0)
                from_word[cw - 'a'] = cp;
            if (from_patt[cp - 'a'] < 0)
                from_patt[cp - 'a'] = cw;
            if (from_word[cw - 'a'] != cp || from_patt[cp - 'a'] != cw)
                return false;
        }
        return true ;
    }
    
};
