class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts)
    {
        int res = -1e9;
        int i = -1;
        while (++i < accounts.size())
        {
            int n = accumulate(accounts[i].begin(), accounts[i].end(), 0);
            res = res < n ? n : res;
        }
        return res;
    }
};
