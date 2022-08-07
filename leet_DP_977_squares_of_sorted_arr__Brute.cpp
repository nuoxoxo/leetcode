class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums)
    {
        int             i = -1;

        while (++i < nums.size()) nums[i] *= nums[i];
        sort(nums.begin(), nums.end());
        return (nums);
    }
};
