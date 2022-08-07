/**
 * @param {number[]} nums
 * @return {number[]}
 */

var runningSum = function(nums) {
    return recurse(nums, 1)
};

var recurse = function(nums, i) {
    if (i == nums.length)
        return nums
    nums[i] += nums[i - 1]
    return recurse(nums, i + 1)
}
