class Solution {
public:
    vector<int> runningSum(vector<int>& nums)
    {
        return recurse(nums, 1);
    }

    vector<int> recurse(vector<int>& nums, int i)
    {
        if (i == (int) nums.size())
            return nums;
        nums[i] += nums[i - 1];
        return recurse(nums, i + 1);
    }
};
