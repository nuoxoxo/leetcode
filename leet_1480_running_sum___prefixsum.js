/**
 * @param {number[]} nums
 * @return {number[]}
 */

var runningSum = function(nums) {
    i = 0
    while (++i < nums.length) {
        nums[i] += res[i - 1]
    }
    return nums
};
