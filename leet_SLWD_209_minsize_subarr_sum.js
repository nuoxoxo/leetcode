/**
 * @param {number} target
 * @param {number[]} nums
 * @return {number}
 */
var minSubArrayLen = function(target, nums) {
    if (nums.includes(target))
        return 1
    res = Number.MAX_SAFE_INTEGER
    yes = false
    add = 0
    i = -1
    j = 0
    while (++i < nums.length) {
        add += nums[i]
        while (add >= target) {
            yes = true
            res = Math.min(res, i - j + 1)
            add -= nums[j]
            j += 1
        }
    }
    if (!yes)
        return 0
    return res
};
