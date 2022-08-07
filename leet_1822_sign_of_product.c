int arraySign(int* nums, int numsSize)
{
    int i = -1, a = 1 ;

    while (++i < numsSize)
    {
        if (!nums[i])   return 0 ;
        if (nums[i]<0)  a=-a ;
        
    }
    return a < 0 ? -1 : 1 ;
}
