/**
 * @param {number[]} coins
 * @param {number} amount
 * @return {number}
 */
var coinChange = function(coins, n) {
    coins.sort((a, b) => a - b)
    dp = Array(++n).fill(n)
    dp[0] = 0
    i = 0
    while (++i < n) {
        for (let c of coins) {
            if (i < c)
                break
            dp[i] = Math.min(dp[i], dp[i - c] + 1)
        }
    }
    if (dp[n - 1] == n)
        return -1
    return dp[n - 1]
};
