class Solution {
public:
    int kthFactor(int n, int k)
    {
        int i = 0;
        while (++i < n + 1)
        {
            if (n % i)
                continue ;
            --k;
            if (!k)
                return i;
        }
        return -1;
    }
};
