

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int* sortArray(int* nums, int numsSize, int* returnSize)
{
    quicksort(nums, 0, numsSize - 1);
    *returnSize = numsSize;
    return nums ;
}

void    quicksort(int *arr, int L, int R)
{
    if (L >= R)
{
    return ;
}
    int i = L;
    int j = R;
    int p = i + rand() % (j - i + 1);
    int tmp = arr[p];
    arr[p] = arr[i];
    arr[i] = tmp;
    while (i < j)
    {
        while (i < j && tmp <= arr[j])
        {
            --j;
        }
        arr[i] = arr[j];
        while (i < j && tmp >= arr[i])
        {
            ++i;
        }
        arr[j] = arr[i];
    }
    arr[i] = tmp;
    quicksort(arr, L, i - 1);
    quicksort(arr, i + 1, R);
}

