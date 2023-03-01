class Solution {
public:
    int searchInsert(vector<int>& nums, int target)
    {
        int i = -1;
        while (++i < nums.size())
        {
            if (nums[i] >=  target)
                return i;
        }
        return nums.size();
    }
};
