class Solution {
public:
    int maximumGap(vector<int>& nums)
    {
        int len = (int) nums.size();
        int res = 0;
        if (len < 2)
            return 0;
        sort(nums.begin(), nums.end());
        int i = 0;
        while (++i < len)
            res = max(res, nums[i] - nums[i - 1]);
        return res;
    }
};
