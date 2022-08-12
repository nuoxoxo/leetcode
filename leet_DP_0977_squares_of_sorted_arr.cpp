class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums)
    {
        int             n = nums.size();
        int             R = n - 1;
        int             L = 0;
        vector<int>     dp(n);

        while (L <= R)
        {
            --n;
            if (abs(nums[L]) < abs(nums[R]))
                dp[n] = nums[R] * nums[R--];
            else
                dp[n] = nums[L] * nums[L++];
        }
        return (dp);
    }
};
