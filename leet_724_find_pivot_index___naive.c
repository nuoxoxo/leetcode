

int pivotIndex(int* nums, int numsSize)
{
    float   cur;
    int     sum, i;

    i = -1;
    sum = 0;
    while (++i < numsSize)
    {
        sum += nums[i];
    }
    cur = 0;
    i = -1;
    while (++i < numsSize)
    {
        if (i)
        {
            cur += nums[i - 1];
        }
        if (cur == (float) (sum - nums[i]) / 2)
        {
            return (i);
        }
    }
    return (-1);
}
