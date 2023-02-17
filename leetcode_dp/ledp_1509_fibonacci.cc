class Solution {
public:
    int fib(int n)
    {
        if (n < 2)
            return n;
        vector<int> f(n + 1, 0);
        f[0] = 0;
        f[1] = 1;
        int i = 1;
        while (++i < n + 1)
        {
            f[i] = f[i - 1] + f[i - 2];
        }
        return f[n];
    }
};
