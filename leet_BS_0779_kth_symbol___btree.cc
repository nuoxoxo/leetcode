class Solution {
public:
    int kthGrammar(int n, int k)
    {
        long long   L = 1, R = 1;
        int res = 0;
        int i = -1;
        while (++i < n - 1)
            R *= 2;
        i = -1;
        while (++i < n - 1)
        {
            int mid = (R - L) / 2 + L;
            if (mid < k)
            {
                L = mid + 1;
                res ^= 1;
            }
            else
            {
                R = mid;
            }
        }
        return res;
        
    }
};
