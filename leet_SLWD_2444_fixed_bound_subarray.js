/**
 * @param {number[]} nums
 * @param {number} minK
 * @param {number} maxK
 * @return {number}
 */

var countSubarrays = function(nums, minK, maxK) {
    let res = 0
    let L = 0, R = 0
    let foundL = false, foundR = false
    let start = 0, i = -1
    while (++i < nums.length) {
        if (nums[i] < minK || nums[i] > maxK) {
            foundL = foundR = false
            start = i + 1
        }
        if (nums[i] == minK) {
            foundL = true
            L = i
        }
        if (nums[i] == maxK) {
            foundR = true
            R = i
        }
        if (foundL && foundR) {
            res += Math.min(L, R) - start + 1
        }
    }
    return res 
};
