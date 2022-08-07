

int combinationSum4(int* nums, int numsSize, int target)
{
    unsigned int    *dp;
    int             i, j;

    //dp = malloc(sizeof(unsigned long long) * (target + 1));
    /* both work */
    dp = calloc(target + 1, sizeof(unsigned int));
    if (! dp)
        return -1;
    i = 0;
    while (++i < target + 1)
        dp[i] = 0;
    dp[0] = 1;
    i = 0;
    while (++i < target + 1)
    {
        j = -1;
        while (++j < numsSize)
        {
            
            if (i - nums[j] > -1)
            {
                dp[i] += dp[i - nums[j]];
            }
        }
    }
    return dp[target];
}
