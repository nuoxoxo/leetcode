class Solution {
    public int combinationSum4(int[] nums, int target)
    {
        int[]   dp = new int[target + 1];
        int     i, j;

        Arrays.fill(dp, 0);
        dp[0] = 1;
        i = 0;
        while (++i < target + 1)
        {
            j = -1;
            while (++j < nums.length)
            {
                if (i - nums[j] > -1)
                    dp[i] += dp[i - nums[j]];
            }
        }
        return dp[target];
    }
}
