/**
 * @param {number[]} nums
 * @return {number}
 */
var longestConsecutive = function(n) {
    let len = n.length
    if (len < 2)
        return len
    n.sort((a, b) => a - b)
    let dp = [...Array(len)].fill(1)
    let res = 0
    let i = 0
    while (++i < len) {
        let dif = n[i] - n[i - 1]
        if (dif < 2)
            dp[i] = dp[i - 1] + dif
    }
    return Math.max(...dp)
};
