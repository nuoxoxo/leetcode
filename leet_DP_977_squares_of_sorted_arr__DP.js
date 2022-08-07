/**
 * @param {number[]} nums
 * @return {number[]}
 */

var sortedSquares = function(nums) {
    let len = nums.length
    let R = len - 1
    let L = 0
    let dp = new Array(len)
    while (L <= R) {
        --len
        if (Math.abs(nums[L]) < Math.abs(nums[R]))
            dp[len] = nums[R] * nums[R--]
        else
            dp[len] = nums[L] * nums[L++]
    }
    return dp
};
