/**
 * @param {number[]} cost
 * @return {number}
 */
var minCostClimbingStairs = function(cost) {
    let n = cost.length + 1
    let dp = new Array(n)
    dp[0] = dp[1] = 0
    let i = 1
    while (++i < n) {
        let left = dp[i - 2] + cost[i - 2]
        let right = dp[i - 1] + cost[i - 1]
        dp[i] = Math.min(left, right)
    }
    return dp[n - 1]
};
