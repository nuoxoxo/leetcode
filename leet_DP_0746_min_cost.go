func minCostClimbingStairs(cost []int) int {
    size := len(cost)
	dp := make([]int, size + 1)
	for i := 2; i < size + 1; i++ {
		l := dp[i - 2] + cost[i - 2]
		r := dp[i - 1] + cost[i - 1]
		if l < r {
			dp[i] = l
		} else {
			dp[i] = r
		}
	}
	return dp[size]
}
