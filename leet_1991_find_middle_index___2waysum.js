/**
 * @param {number[]} nums
 * @return {number}
 */
var findMiddleIndex = function(nums) {
    right = 0
    left = 0
    i = -1
    total = nums.reduce((a, b) => a + b)
    while (++i < nums.length) {
        right = total - nums[i] - left
        if (left == right)
            return i
        left += nums[i]
    }
    return -1
};
