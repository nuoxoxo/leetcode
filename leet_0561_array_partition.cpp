class Solution {
public:
    int arrayPairSum(vector<int>& nums)
    {
        int     res, i;

        sort(nums.begin(), nums.end());
        i = 0;
        res = 0;
        while (i < (int) nums.size())
        {
            res += nums[i];
            i += 2;
        }
        return res ;
    }
};
