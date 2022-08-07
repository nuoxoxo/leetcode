class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& n)
    {
        vector<vector<int>> res;
        sort(n.begin(), n.end());
        res.push_back(n);
        while (next_permutation(n.begin(), n.end()))
            res.push_back(n);
        return res;
    }
};
