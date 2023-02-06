class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n)
    {
        vector<int> r;
        int         i = -1;
        while (++i < n)
            r.insert(r.end(), {nums[i], nums[i + n]});
        return r;
    }
};
