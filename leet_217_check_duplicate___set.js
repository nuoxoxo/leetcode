/**
 * @param {number[]} nums
 * @return {boolean}
 */

var containsDuplicate = function(nums) {
    s = new Set()
    for (let n of nums) {
        if (s.has(n))
            return true
        s.add(n)
    }
    return false
};
