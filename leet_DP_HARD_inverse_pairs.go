func kInversePairs(n int, k int) int {
    const MOD = 1_000_000_007
    // var dp [k + 1]int
    dp := make([]int, k+1)
    dp[0] = 1
    for i := 1; i < n + 1; i++ {
        // var cp [k + 1]int
        cp := make([]int, k+1)
        temp := 0
        for kk := 0; kk < k + 1; kk++ {
            if kk > i - 1 {
                temp = (temp - dp[kk - i] + MOD) % MOD
            }
            temp = (temp + dp[kk]) % MOD
            cp[ kk ] = temp
        }
        dp = cp
    }
    return dp[k]
}
