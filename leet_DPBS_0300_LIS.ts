function lengthOfLIS(nums: number[]): number {
    let len: number = nums.length
    let dp: number[] = new Array(len).fill(1)
    // console.log(dp)
    let i = len, j
    while (--i > -1) {
        j = i
        while (++j < len) {
            if (nums[i] < nums[j]) {
                if (dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1
                }
            }
        }
    }
    return Math.max(...dp)
};
