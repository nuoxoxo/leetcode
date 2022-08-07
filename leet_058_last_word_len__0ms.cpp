class Solution {
public:
    int lengthOfLastWord(string s)
    {
        int i = s.length(), len = 0 ;

        while (--i > -1)
        {
            if (s[i] == 32 && len > 0)
                return len ;
            if (s[i] != 32)
                len ++ ;
        }
        return len ;
    }
};
