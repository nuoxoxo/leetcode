int singleNumber(int* nums, int numsSize)
{
    int i = -1, n = 0 ;
    while (++i < numsSize)  n ^= nums[i] ;
    return (n);
}
