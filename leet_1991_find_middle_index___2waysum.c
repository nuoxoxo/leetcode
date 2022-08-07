

int findMiddleIndex(int* nums, int numsSize){
    int     total;
    int     right;
    int     left;
    int     i;

    i = -1;
    total = 0;
    while (++i < numsSize)
        total += nums[i];
    right = 0;
    left = 0;
    i = -1;
    while (++i < numsSize)
    {
        right = total - nums[i] - left;
        if (left == right)
            return (i);
        left += nums[i];
    }
    return (-1);
}
