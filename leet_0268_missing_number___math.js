/**
 * @param {number[]} nums
 * @return {number}
 */
var missingNumber = function(nums) {
    n = nums.length
    // return n * Math.floor((n + 1) / 2) - nums.reduce((a, b) => a + b, 0)
    return Math.floor(n * (n + 1) / 2) - nums.reduce((a, b) => a + b, 0)
};
