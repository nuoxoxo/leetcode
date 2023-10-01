class Solution {
public:
    bool find132pattern(vector<int>& nums)
    {
        int n = nums.size();
        if (n < 3)
            return false;
        int third = -1e9; // for each i, find and delete the smallest 3rd on the right
        int i = n - 1;
        int j = n;
        while (i > -1)
        {
            if (nums[i] < third)
                return true;
            while (j < n && nums[i] > nums[j])
            {
                third = nums[j];
                ++j;
            }
            // --j;
            nums[--j] = nums[i--];
            // --i;
        }
        return false;
    }
};
