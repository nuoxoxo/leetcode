long long countSubarrays(int* nums, int numsSize, int minK, int maxK)
{
    long long   res = 0;
    int R = 0, L = 0;
    int start = 0;
    int foundL = 0, foundR = 0;
    int i = -1;
    while (++i < numsSize)
    {
        if (nums[i] < minK || nums[i] > maxK)
        {
            foundL = 0;
            foundR = 0;
            start = i + 1;
        }
        if (nums[i] == minK)
        {
            foundL = 1;
            L = i;
        }
        if (nums[i] == maxK)
        {
            foundR = 1;
            R = i;
        }
        if (foundL && foundR)
        {
            res += (L < R ? L : R ) - start + 1;
        }
    }
    return res;
}
