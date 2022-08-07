class Solution {
public:
    vector<int> countBits(int n)
    {
        vector<int> E(n + 1, 0);
        int         i = -1;
        while (++i < n + 1)
        {
            E[i] = E[i / 2] + (i % 2);
        }
        return E ;
    }
};
