var majorityElement = function(nums)
{
    if (nums.length == 1)
        return nums[0]
    count = 1
    c = 1e9
    for (let n of nums)
    {
        if (c ^ n)
        {
            count--
            if (!count)
            {
                count = 1
                c = n
            }
        }
        else    count++
    }
    return c
};
