class Solution {
public:
    bool repeatedSubstringPattern(string s)
    {
        string  ls = s + s;

        ls = ls.substr(1, ls.length() - 2);
        if (ls.find(s) == string::npos)
            return false ;
        return true ;
    }
};
