/**
 * @param {number[]} nums
 * @return {number}
 */

var maxSubArray = function(n) {
    res = n[0]
    i = 0
    while (++ i < n.length){
        n[i] = Math.max(n[i] + n[i - 1], n[i])
        res = Math.max(n[i], res)
    }
    return res
};
