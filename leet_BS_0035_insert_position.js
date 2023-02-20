/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */

var searchInsert = function(nums, target) {
    let n = nums.length
    let mid, R = n - 1, L = 0
    while (L <= R) {
        mid = Math.floor((R - L) / 2) + L
        if (nums[mid] < target)
            L = mid + 1
        else if (nums[mid] > target)
            R = mid - 1
        else
            return mid
    }
    return L
};
