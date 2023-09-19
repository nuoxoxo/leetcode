class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes)
    {
        vector<vector<int>> res;
        unordered_map<int, vector<int>> D;
        int i = -1;
        while (++i < (int) groupSizes.size())
        {
            int len = groupSizes[i];
            D[len].push_back(i);
            if (D[len].size() == len)
            {
                res.push_back(D[len]);
                D[len].clear();
            }
        }
        return res;
    }
};
