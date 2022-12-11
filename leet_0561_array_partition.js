/**
 * @param {number[]} nums
 * @return {number}
 */

var arrayPairSum = function(nums) {
    nums.sort((a, b) => a - b)
    let i = 0
    let res = 0
    while (i < nums.length) {
        res += nums[i]
        i += 2
    }
    return res
};
