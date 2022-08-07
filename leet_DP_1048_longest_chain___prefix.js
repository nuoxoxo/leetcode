/**
 * @param {string[]} words
 * @return {number}
 */
var longestStrChain = function(arr) {
    arr.sort((a, b) => a.length - b.length)
    dp = {}
    res = 1
    for (let s of arr) {
        i = -1
        while (++i < s.length) {
            let tmp = s.slice(0, i) + s.slice(i + 1)
            if (!dp.hasOwnProperty(tmp))
                dp[tmp] = 0
            if (!dp.hasOwnProperty(s))
                dp[s] = 0
            dp[s] = Math.max(dp[tmp] + 1, dp[s])
        }
        res = Math.max(res, dp[s])
    }
    return res
};
