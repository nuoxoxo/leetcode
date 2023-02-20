/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var searchInsert = function(nums, target) {
    let L = 0
    let R = nums.length - 1
    while (L <= R) {
        let m = Math.floor((R - L) / 2) + L
        if (nums[m] == target)
            return m
        else if (nums[m] < target)
            L = m + 1
        else
            R = m - 1
    }
    return L
};
