/**
 * @param {number[]} nums
 * @return {number}
 */
var missingNumber = function(nums) {
    i = -1
    len = nums.length
    res = len
    while (++i < len)
        res ^= i ^ nums[i]
    return res
};
