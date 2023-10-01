class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k)
    {
        int mx = *max_element(nums.begin(), nums.end());
        int mn = *min_element(nums.begin(), nums.end());
        int diff = mx - mn - k * 2;
        if (diff > 0)
            return diff;
        return 0;
    }
};
