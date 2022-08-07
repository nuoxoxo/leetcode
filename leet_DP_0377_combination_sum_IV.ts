

function combinationSum4(nums: number[], target: number): number {
    let dp: number [] = new Array(target + 1).fill(0)
    dp[0] = 1
    let i = 0
    while (++i < target + 1) {
        for (let n of nums) {
            if (i - n > -1)
                dp[i] += dp[i - n]
        }
    }
    return dp[target]
};
