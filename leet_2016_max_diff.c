int maximumDifference(int* nums, int numsSize)
{
    int i = -1;
    int res = -1;
    int mini = 2147483647;

    while (++i < numsSize)
    {
        mini = nums[i] < mini ? nums[i] : mini;
        if (nums[i] > mini)
        {
            int t = nums[i] - mini;
            res = t > res ? t : res;
        }
    }
    return res;
}
