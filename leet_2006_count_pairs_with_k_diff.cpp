class Solution {
public:
    int countKDifference(vector<int>& nums, int k)
    {
        int r = 0;
        int len = nums.size(), i = -1, j;

        while (++i < len)
        {
            j = i;
            while (++j < len)
            {
                if (abs(nums[i] - nums[j]) == k)
                    r++;
            }
        }
        return r;
    }
};
