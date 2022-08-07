/**
 * @param {number[]} nums
 * @return {number}
 */

var findLHS = function(nums) {
    obj = new Object()
    for (let n of nums) {
        if (obj.hasOwnProperty(n))
            obj[n] += 1
        else
            obj[n] = 1
    }
    let res = 0
    for (let n of nums) {
        if (obj.hasOwnProperty(n) && obj.hasOwnProperty(n + 1))
            res = Math.max(obj[n] + obj[n + 1], res)
    }
    return res
};
