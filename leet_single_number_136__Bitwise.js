var singleNumber = function(nums)
{
    let i = 0
    for (let n of nums) i ^= n
    return i
};
