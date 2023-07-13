/**
 * @param {number[]} nums
 * @param {number} k
 * @return {boolean}
 */

var containsNearbyDuplicate = function(nums, k) {
    d = new Object()
    i = -1
    while (++i < nums.length) {
        if (d.hasOwnProperty(nums[i]) && Math.abs(d[nums[i]] - i) <= k)
            return true
        d[nums[i]] = i
    }
    return false
};
