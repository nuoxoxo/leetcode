class Solution {
public:
    vector<int> runningSum(vector<int>& nums)
    {
        int i = 0;
        while (++i < (int) nums.size())
            nums[i] += nums[i - 1];
        return nums;
    }
};
