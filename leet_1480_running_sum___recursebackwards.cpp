class Solution {
public:
    vector<int> runningSum(vector<int>& nums)
    {
        return recurse(nums, (int) nums.size() - 1);
    }

    vector<int> recurse(vector<int>& nums, int i)
    {
        if (i)
        {
            recurse(nums, i - 1);
            nums[i] += nums[i - 1];
        }
        return nums;
    }
};
