class Solution {
public:
    int appendCharacters(string s, string t)
    {
        int lens = s.length(), lent = t.length();
        int si = -1, ti = 0;
        while (++si < lens)
        {
            if (s[si] == t[ti])
            {
                ti++;
                if (ti == lent)
                    return 0;
            }            
        }
        return lent - ti;
    }
};
