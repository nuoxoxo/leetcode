class Solution {
public:
    int maxOperations(vector<int>& nums, int k)
    {
        int n = nums.size();
        int res = 0;
        int i = 0, j = n - 1;
        sort(nums.begin(), nums.end());
        while (i < j && nums[i] < k)
        {
            if (nums[i] + nums[j] < k)
                ++i;
            else if (nums[i] + nums[j] > k)
                --j;
            else
            {
                ++res;
                ++i;
                --j;
            }
        }
        return res;
    }
};
