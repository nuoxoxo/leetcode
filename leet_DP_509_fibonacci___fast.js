/**
 * @param {number} n
 * @return {number}
 */
var fib = function(n) {
    if (n < 2)
        return n
    let dp = new Array(n + 1)
    dp[0] = 0
    dp[1] = 1
    let i = 1
    while (++i < n + 1) {
        dp[i] = dp[i - 2] + dp[i - 1]
    }
    return dp[n]
};
