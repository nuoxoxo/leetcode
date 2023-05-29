class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums)
    {
        int n = (int) nums.size();
        int pos = 0;
        int i = -1;
        while (++i < n)
        {
            if (nums[i] % 2 == 0)
            {
                swap(nums[pos], nums[i]);
                ++pos;
            }
        }
        return nums;
    }
};
