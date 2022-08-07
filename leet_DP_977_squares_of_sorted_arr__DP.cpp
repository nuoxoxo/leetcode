class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums)
    {
        int n = nums.size() - 1;
        int R = n;
        int L = 0;
        vector<int> dp(n + 1);

        while (L <= R)
        {
            if (abs(nums[L]) < abs(nums[R]))
                dp[n] = nums[R] * nums[R--];
            else
                dp[n] = nums[L] * nums[L++];
            --n;
        }
        return dp;
    }
};
