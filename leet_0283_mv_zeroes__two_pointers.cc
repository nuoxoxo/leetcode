class Solution {
public:
    void moveZeroes(vector<int>& nums)
    {
        int s = nums.size(), i = -1, j = 0;

        while (++i < s)
        {
            if (nums[i])
            {
                nums[j] = nums[i];
                ++j;
            }
        }
        while (j < s)
        {
            nums[j] = 0;
            ++j;
        }
    }
};
