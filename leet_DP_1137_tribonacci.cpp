class Solution {
public:
    int tribonacci(int n)
    {
        if (n < 2)
            return n;
 
        vector<int>     t(n + 1, 0);
        int             i = 2;

        t[1] = 1;
        t[2] = 1;
        while (++i < n + 1)
        {
            t[i] = t[i - 1] + t[i - 2] + t[i - 3];
        }
        return t[n];
    }
};
