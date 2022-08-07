/**
 * @param {number[]} nums
 * @return {boolean}
 */

var canJump = function(nums) {
    let len = nums.length
    if (len === 1)
        return true
    let end, i
    i = end = len - 1
    while (-- i > -1) {
        if (i + nums[i] >= end)
            end = i
    }
    return end === 0
};
