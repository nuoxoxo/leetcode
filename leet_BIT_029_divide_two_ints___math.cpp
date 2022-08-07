class Solution {
public:
    int divide(int dd, int dv)
    {
        if (dd == -2147483648 && dv == -1)
            return 2147483647;
        if (dd == -2147483648 && dv == 1)
            return dd;

        long    d = labs((long) dd);
        long    v = labs((long) dv);
        long    res = 0, sign;

        while (d >= v)
        {
            long    temp = v;
            long    fact = 1;
            while (d >= temp)
            {
                d -= temp;
                res += fact;
                fact <<= 1;
                temp <<= 1;
            }
        }
        sign = (dd > 0 && dv > 0) || (dd < 0 && dv < 0) ? 1 : -1;
        return res * sign;
    }
};
