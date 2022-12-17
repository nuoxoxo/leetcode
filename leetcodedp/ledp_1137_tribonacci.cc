class Solution {
public:
    int tribonacci(int n) 
    {
        if (n < 2)
            return n;
        vector<int> f(n + 1, 0);
        f[1] = 1;
        f[2] = 1;
        int i = 2;
        while (++i < n + 1)
        {
            f[i] = f[i - 3] + f[i - 2] + f[i - 1];
        }
        return f[n];
    }
};
