class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums)
    {
        std::map<int, vector<int>> D;
        int r = -1, c;
        while (++r < nums.size())
        {
            c = -1;
            while (++c < nums[r].size())
                D[r + c].push_back(nums[r][c]);
        }
        vector<int> res;
        auto p = D.begin();
        while (p != D.end())
        {
            while ( ! p->second.empty())
            {
                res.push_back(p->second.back());
                p->second.pop_back();
            }
            ++p;
        }
        return res;
    }
};
