class Solution {
public:
    bool isSubsequence(string s, string t)
    {
        int len = s.length(), i = 0 ;
        if (!len)
            return true ;
        if (!t.length())
            return false ;
        for (char c: t)
        {
            if (s[i] == c)  i++ ;
            if (len == i)   return true ;
        }
        return false ;
    }
};
