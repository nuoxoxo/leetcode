func sortedSquares(nums []int) []int {
    n := len(nums)
    L, R := 0, n - 1
    dp := make([]int, n) // ie. vi dp(n);
    for L <= R {
        n--
        if abs(nums[L]) < abs(nums[R]) {
            dp[n] = nums[R] * nums[R]
            R--
        } else {
            dp[n] = nums[L] * nums[L]
            L++
        }
    }
    return dp
}

func abs(n int) int {
    if n > 0 {
        return n
    }
    return -n
}
