class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums)
    {
        vector<int> res;
        res.reserve(nums.size() * 2);
        res.reserve(nums.size() * 2);
        res.insert(res.end(), nums.begin(), nums.end());
        res.insert(res.end(), nums.begin(), nums.end());
        return res;
    }
};
