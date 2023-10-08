class Solution {
public:
    bool checkPerfectNumber(int num)
    {
        if (num < 2)
            return false;
        int res = 1;
        double sqr = sqrt(num);
        int n = 1;
        while (++n < sqr)
        {
            if (num % n)
                continue ;
            res += n + num / n;
        }
        if (num % n == 0 && (int) sqr >= n)
            res += n;
        return res == num;
    }
};
