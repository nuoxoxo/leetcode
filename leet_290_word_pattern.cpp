class Solution {
public:
    bool wordPattern(string pattern, string s)
    {
        int plen = pattern.length();
        if (plen != count(s.begin(), s.end(), ' ') + 1)
            return false ;

        map<string, char>   wmap;
        map<char, string>   pmap;
        stringstream        ss(s);
        string              w;
        int                 i = -1;
        while (++ i < plen && ss >> w)
        {
            char    c = pattern[i];
            if (pmap.find(c) == pmap.end() && wmap.find(w) == wmap.end())
            {
                pmap[c] = w;
                wmap[w] = c;
            }
            else if (pmap.find(c) != pmap.end() && pmap[c] != w)
                return false;
            else if (wmap.find(w) != wmap.end() && wmap[w] != c)
                return false;
        }
        return true ;
    }
};
