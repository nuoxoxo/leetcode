class Solution {
public:
    int findDuplicate(vector<int>& nums)
    {
        int len = nums.size();
        if (len == 2)
            return nums[0];
        sort(nums.begin(), nums.end());
        int i = 1;
        int j = len - 2;
        int mid = len / 2;
        while (i ^ j && i < mid && j > mid)
        {
            if (nums[i] == nums[i - 1])
                return nums[i];
            if (nums[j] == nums[j + 1])
                return nums[j];
            ++i;
            --j;
        }
        return nums[mid];
    }
};
