class Solution {
public:
    #include "numeric"
    string gcdOfStrings(string str1, string str2)
    {
        if (str1 + str2 != str2 + str1)
            return "";
        int len1 = str1.length(), len2 = str2.length();
        string  s = len1 > len2? str1: str2;
        string  res;
        // int  L = GCD(len1, len2);
        int L = std::gcd(len1, len2);
        int     i = -1;
        while (++i < L)
            res += s[i];
        return res;
    }

    // int GCD(int a, int b)
    // {
    //     int res = min(a, b);
    //     while (res)
    //     {
    //         if (!(a % res) && !(b % res))
    //             break ;
    //         --res;
    //     }
    //     return res ;
    // }
};
