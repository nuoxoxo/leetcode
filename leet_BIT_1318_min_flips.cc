class Solution {
public:
    int minFlips(int a, int b, int c)
    {
        long long aa, bb, cc;
        long res = 0;
        while (a > 0 || b > 0 || c > 0)
        {
            aa = a % 2;
            bb = b % 2;
            cc = c % 2;
            if (cc == 1 && aa + bb == 0)
                ++res;
            else if ( ! cc)
                res += aa + bb;
            a /= 2;
            b /= 2;
            c /= 2;

        }
        return (int) res;
    }
};
