/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */

var smallestRangeI = function(nums, k) {
    let diff = Math.max(...nums) - Math.min(...nums) - k * 2
    if (diff > 0)
        return diff
    return 0
};
