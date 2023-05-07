func lengthOfLIS(nums []int) int {
    dp := make([]int, len(nums))
    for i := 0; i < len(nums); i++ {
        dp[i] = 1
    }
    for i := len(nums) - 1; i > -1; i-- {
        for j := i + 1; j < len(nums); j++ {
            if nums[i] < nums[j] {
                if dp[i] < dp[j] + 1 {
                    dp[i] = dp[j] + 1
                }
            }
        }
    }
    res := 0
    for i, n := range dp {
        if i == 0 || n > res {
            res = n
        }
    }
    return res
}
