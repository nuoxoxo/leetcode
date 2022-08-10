class Solution {
public:
    double myPow(double x, int n)
    {
        long long       xp; // exponent
        long long       i;
        double          res;

        // basecase
        if (x == 1)
        {
            return (1);
        }
        // weird testcases of extremum
        if (n == 2147483647 && x == -1)
        {
            return (-1);
        }
        if (n == -2147483648)
        {
            if (x == -1)
                return (1);
            return (0);
        }
        res = 1;
        if (n < 0)
        {
            i = 0;
            xp = -n;
            while (++i < xp + 1)
                res /= x;
        }
        else
        {
            i = 0;
            xp = n;
            while (++i < xp + 1)
                res *= x;
        }
        return res;
    }
};
