

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *searchRange(int* nums, int numsSize, int target, int* returnSize)
{
    int     mid, i, j;
    int     *res;

    res = malloc(sizeof(int) * 2);
    *returnSize = 2;
    res[0] = -1;
    res[1] = -1;
    i = 0;
    j = numsSize - 1;
    while (i <= j)
    {
        mid = (j - i) / 2 + i;
        if (nums[mid] == target)
        {
            i = j = mid;
            while (i > -1 && nums[i] == target)
                --i;
            while (j < numsSize && nums[j] == target)
                ++j;
            res[0] = i + 1;
            res[1] = j - 1;
            return res;
        }
        else if (nums[mid] < target)
            i = mid + 1;
        else
            j = mid - 1;
    }
    return res;
}
