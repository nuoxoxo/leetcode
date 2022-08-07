
int qs(int *a, int *b);

int longestConsecutive(int* n, int numsSize)
{
    int     res, i, t;

    if (numsSize < 2)
        return (numsSize);
    int     dp[numsSize];
    // if (!(dp = malloc(numsSize * sizeof(int))));
        // return 0;
    i = -1;
    while (++i < numsSize)
        dp[i] = 1;
    qsort(n, numsSize, sizeof(int), qs);
    i = 0;
    while (++i < numsSize)
    {
        t = n[i] - n[i - 1];
        if (t < 2)
            dp[i] = dp[i - 1] + t;
    }
    res = 0;
    i = -1;
    while (++i < numsSize)
    {
        res = res > dp[i] ? res : dp[i]; 
    }
    return (res);
}

int qs(int *a, int *b)
{
    return (*(int *) a - *(int *) b);
}
