/**
 * @param {number[]} nums
 * @return {boolean}
 */
var find132pattern = function(nums) {
    n = nums.length
    if (n < 3)
        return false
    third = Number.MIN_SAFE_INTEGER
    i = n - 1
    m = n
    while (i > -1) {
        if (nums[i] < third)
            return true
        while (m < n && nums[i] > nums[m]) {
            third = nums[m];
            ++m
        }
        nums[--m] = nums[i--]
    }
    return false
};
