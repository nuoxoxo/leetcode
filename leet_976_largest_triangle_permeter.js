/**
 * @param {number[]} nums
 * @return {number}
 */
var largestPerimeter = function(nums) {
    nums.sort((a, b) => b - a)
    console.log(nums)
    i = -1
    while (++i < nums.length - 2) {
        if (nums[i] < nums[i + 1] + nums[i + 2])
            return nums[i] + nums[i + 1] + nums[i + 2]
    }
    return 0
};
