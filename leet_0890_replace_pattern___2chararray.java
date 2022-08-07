class Solution {
    public List<String> findAndReplacePattern(String[] words, String pattern)
    {
        // vector<string>      res;
        List<String>        res = new ArrayList<>();

        for (String w: words)
        {
            if (valid(w, pattern))
                // res.push_back(w);
                res.add(w);
        }
        return res;
    }

    private boolean     valid(String w, String p)
    {
        char[]          from_word = new char[26];
        char[]          from_patt = new char[26];
        char            cw, cp;
        int             len, i;

        Arrays.fill(from_word, '~');
        Arrays.fill(from_patt, '~');
        len = w.length();
        i = -1;
        while (++i < len)
        {
            cw = w.charAt(i);
            cp = p.charAt(i);
            if (from_word[cw - 'a'] == '~')
                from_word[cw - 'a'] = cp;
            if (from_patt[cp - 'a'] == '~')
                from_patt[cp - 'a'] = cw;
            if (from_word[cw - 'a'] != cp || from_patt[cp - 'a'] != cw)
                return false;
        }
        return true ;
    }
    
}
