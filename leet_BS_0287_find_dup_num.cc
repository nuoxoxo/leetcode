class Solution {
public:
    int findDuplicate(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        if (n == 2)
            return nums[0];
        int i = 0, j = n - 1;
        while (++i != --j && i < n / 2 && j > n / 2)
        {
            if (nums[i] == nums[i - 1])
                return nums[i];
            if (nums[j] == nums[j + 1])
                return nums[j];
        }
        return nums[i] ;
    }
};
