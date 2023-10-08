func integerBreak(n int) int {
    if n < 4 {
		return n - 1
	}
	dp := make([]int, n + 1)
	dp[2] = 1 * 1
	for i := 3; i < n + 1; i++ {
		for j := 1; j < i / 2 + 1; j++ {
			temp := math.Max(float64(dp[i - j] * j), float64((i - j) * j))
            dp[i] = int(math.Max(float64(dp[i]), temp))
		}
	}
	return dp[n]
}
