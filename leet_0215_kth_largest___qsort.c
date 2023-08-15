int cmp(int *a, int *b);

int findKthLargest(int* nums, int numsSize, int k)
{
    qsort(nums, numsSize, sizeof(int), &cmp); // also works w/o '&'
    return nums[k - 1];
}

int cmp(int *a, int *b)
{
    return (*b - *a);
}
