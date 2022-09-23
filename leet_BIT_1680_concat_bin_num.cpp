class Solution {
#define ll long long
public:
    int concatenatedBinary(int n)
    {
        ll      res, two;
        int     temp, i;

        two = 1;
        res = 0;
        i = n + 1;
        while (--i)
        {
            res = (res + two * i) % int(1e9 + 7);
            temp = i;
            while (temp)
            {
                two = (two * 2) % int(1e9 + 7);
                temp /= 2;
            }
        }
        return res;
    }
};
