class Solution {
public:
    bool areAlmostEqual(string s1, string s2)
    {
        if (s1 == s2)   return true ;

        int len = s1.length();
        if (len ^ s2.length())  return false ;

        string  tmp1 = "", tmp2 = "" ;
        int     n = 0, i = -1;
        while (++i < len)
        {
            if (s1[i] ^ s2[i])
            {
                tmp1 += s1[i];
                tmp2 += s2[i];
                n++;
            }
            if (n > 2)  return false ;
        }
        if (n ^ 2)  return false ;
        sort(tmp1.begin(), tmp1.end());
        sort(tmp2.begin(), tmp2.end());
        if (tmp1 == tmp2)   return true ;
        return false ;
    }
};
