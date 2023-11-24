class Solution {
public:
    int maxCoins(vector<int>& p/*iles*/)
    {
        sort(p.begin(), p.end(), greater<>{});
        int i = 1;
        int res = 0;
        while (i < p.size() - p.size() / 3)
        {
            res += p[i];
            i += 2;
        }
        return res;
    }
};
