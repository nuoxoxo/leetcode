/**
 * @param {number} target
 * @param {number[]} nums
 * @return {number}
 */
var minSubArrayLen = function(target, nums) {
    if (nums.includes(target))
        return 1
    let res = Number.MAX_SAFE_INTEGER
    let isFound = false
    let n = nums.length
    let i = -1
    while (++i < n) {
        let tooLong = false
        let temp = nums[i]
        let j = i
        while (++j < n && temp < target) {
            if (j - i >= res) {
                tooLong = true
                break
            }
            temp += nums[j]
        }
        if (!tooLong && temp >= target && j - i < res) {
            res = j - i
            isFound = true
        }
    }
    if (!isFound)
        return 0
    return res
};
