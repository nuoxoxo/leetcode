class Solution {
public:
    int findMiddleIndex(vector<int>& nums)
    {
        int     L, R, i, sum;

        L = 0;
        R = 0;
        i = -1;
        sum = accumulate(nums.begin(), nums.end(), 0);
        while (++i < (int) nums.size())
        {
            R = sum - L - nums[i];
            if (L == R)
                return (i);
            L += nums[i];
        }
        return (-1);
    }
};
