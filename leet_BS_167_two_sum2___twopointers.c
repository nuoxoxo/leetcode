

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* n, int numbersSize, int target, int* returnSize)
{
    int *res;
    *returnSize = 2;
    res = (int*) malloc(2 * sizeof(int));
    if (!res)
        return NULL;
    int r = numbersSize - 1;
    int i = 0;
    if (r > 1)
    {
        while (i < r)
        {
            int t = n[i] + n[r];
            if (t == target)
                break;
            if (t < target)
                ++i;
            else
                --r;
        }
    }
    res[0] = 1 + i;
    res[1] = 1 + r;
    return res;
}
