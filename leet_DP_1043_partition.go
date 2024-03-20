func maxSumAfterPartitioning(arr []int, k int) int {
    N := len(arr)
    dp := make([]int, N)
    bigger := arr[0]
    i := 0
    for i < k {
        if bigger < arr[i] {
            bigger = arr[i]
        }
        dp[i] = bigger * (i + 1)
        i++
    }
    // assert i == k
    for i < N {
        bigger = arr[i]
        dp[i] = dp[i - 1] + bigger
        j := i - 1
        for j > i - k {
            if bigger < arr[j] {
                bigger = arr[j]
            }
            temp := bigger * (i - j + 1) + dp[j - 1]
            if dp[i] < temp {
                dp[i] = temp
            }
            j--
        }
        i++
    }
    return dp[N - 1]
}
