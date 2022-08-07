/**
 * @param {number[]} nums
 * @return {number[]}
 */
var runningSum = function(nums) {
    n = nums.length
    res = new Array(n).fill(0)
    run = 0
    i = -1
    while (++i < n) {
        run += nums[i]
        res[i] = run
    }
    return res
};
