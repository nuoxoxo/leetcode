/**
 * @param {number[]} nums
 * @return {number}
 */

var maximumDifference = function(nums) {
    let mini = Number.MAX_SAFE_INTEGER
    let res = -1
    for (let n of nums) {
        mini = Math.min(n, mini)
        if (n > mini) {
            res = Math.max(res, n - mini)
        }
    }
    return res
};
