/**
 * @param {number[]} nums
 * @return {number}
 */

var deleteAndEarn = function(nums) {
    let len = nums.length
    let mx = Math.max(...nums)
    let dp = new Array(mx + 1)
    dp.fill(0)
    for (let n of nums)
        dp[n] += n
    let i = 1
    while (++i < mx + 1)
        dp[i] = Math.max(dp[i] + dp[i - 2], dp[i - 1])
    return Math.max(...dp)
};
