/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var combinationSum4 = function(nums, target) {
    dp = new Array(target + 1).fill(0)
    dp[0] = 1;
    i = 0
    while (++i < target + 1) {
        for (let n of nums) {
            if (i - n > -1)
                dp[i] += dp[i - n]
        }
    }
    return dp[target]
};
