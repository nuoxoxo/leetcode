/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var searchInsert = function(nums, target) {
    let i = -1
    while (++i < nums.length) {
        if (nums[i] >= target)
            return i
    }
    return nums.length
};
