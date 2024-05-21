class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums)
    {
        int i = -1;
        vector<vector<int>> res = {{}};
        for (int n: nums)
        {
            int S = res.size();
            int j = -1;
            while (++j < S)
            {
                res.push_back(res[j]);
                res.back().push_back(n);
            }
        }
        return res;
    }
};
