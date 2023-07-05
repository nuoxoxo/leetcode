class Solution {
public:
    int longestSubarray(vector<int>& n)
    {
        int tt = 1;
        int L = 0;
        int R = -1;
        while (++R < (int) n.size())
        {
            if (n[R] == 0)
                --tt;
            if (tt < 0)
            {
                if (n[L] == 0)
                    ++tt;
                ++L;
            }
        }
        return R - L - 1;
    }
};
