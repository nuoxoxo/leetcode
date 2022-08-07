/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* runningSum(int* nums, int ns, int* rs)
{
    int*    res;
    if (!(res = (int*) malloc(sizeof(int) * ns)))
        return NULL;
    int i;

    i = 0;
    *rs = ns;
    res[0] = nums[0];
    while (++i < ns)
    {
        res[i] = res[i - 1] + nums[i];
    }
    return res;
}
