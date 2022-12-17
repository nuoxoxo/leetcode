class Solution {
public:
    int climbStairs(int n)
    {
        if (n < 3)
            return n;
        vector<int> f(n, 0);
        f[0] = 1;
        f[1] = 2;
        int i = 1;
        while (++i < n)
            f[i] = f[i - 1] + f[i - 2];
        return f[n - 1];
    }
};
