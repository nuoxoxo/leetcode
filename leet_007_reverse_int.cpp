class Solution {
public:
    int reverse(int x)
    {
        long    res = 0 ;

        while (x)
        {
            res *= 10 ;
            res += x % 10;
            x /= 10;
        }
        if (res > 2147483641 || res < -2147483641)
            return 0 ;
        return res ;
    }
};
