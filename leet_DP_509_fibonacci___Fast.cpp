class Solution {
public:
    int fib(int n)
    {
        int     f[n + 1];
        int     i;

        if (n < 2)
            return (n);
        f[0] = 0;
        f[1] = 1;
        i = 1;
        while (++i < n + 1)
            f[i] = f[i - 2] + f[i - 1];
        return (f[n]);
    }
};
