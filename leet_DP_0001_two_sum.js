const twoSum = function(nums, target)
{
    const mp = {};
    
    for (let i = 0; i < nums.length; i++)
    {
        if (mp[ nums[i] ] >= 0)
            return [ mp[nums[i] ] , i] 
        mp[ target - nums[i] ] = i
    }
    return {}
};

/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
