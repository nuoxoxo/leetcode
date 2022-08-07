class Solution {
public:
    int singleNumber(vector<int>& nums)
    {
        int     i;

        if (nums.size() == 1)
            return (nums[0]);

        sort(nums.begin(), nums.end());
        if (nums[0] != nums[1])
            return (nums[0]);

        i = -1;
        while (++i < nums.size() - 2)
        {
            if ( nums[i] != nums[i + 1] && nums[i + 1] != nums[i + 2] )
                break;
        }
        return (nums[i + 1]);
    }
};
