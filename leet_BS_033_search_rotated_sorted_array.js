/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */

var search = function(nums, target) {
    let n = nums.length
    let R = n - 1
    let L = 0
    if (nums[L] == target)
        return L
    if (nums[R] == target)
        return R
    while (L < R) {
        let mid = Math.floor((L + R) / 2)
        if (nums[mid] == target)
            return mid
        if (nums[0] < nums[mid]) {
            if (nums[0] < target && target < nums[mid])
                R = mid
            else
                L = mid + 1
        } else {
            if (nums[mid] < target && target < nums[n - 1])
                L = mid + 1
            else
                R = mid
        }
    }
    return -1
};
