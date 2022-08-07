/**
 * @param {number[]} coins
 * @param {number} amount
 * @return {number}
 */

var coinChange = function(coins, amount) {
    let dp = Array(amount + 1).fill(amount + 1)
    dp[0] = 0
    let i = 0
    while (++i < amount + 1) {
        for (let c of coins) {
            if (i >= c) {
                dp[i] = Math.min(dp[i], dp[i - c] + 1)
            }
        }
    }
    if (dp[amount] == amount + 1)
        return -1
    return dp[amount]
};
