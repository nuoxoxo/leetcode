func findPaths(m int, n int, maxMove int, startRow int, startColumn int) int {
    Solutions := []func(int, int, int, int, int) int {
        DP_iterative_tabulation,
    }
    return Solutions[ rand.Intn(len(Solutions)) ]( m, n, maxMove, startRow, startColumn )
}

func DP_iterative_tabulation(m, n, maxMove, startRow, startColumn int) int {

    fmt.Println("/DP_iterative_tabulation")

    MOD := 1_000_000_007//int(1e9 + 7)
    DR := []int{-1,0,1,0}
    DC := []int{ 0,1,0,-1}

    dp := make([][]int, m)
	for i := 0; i < m; i++ {
        dp[i] = make([]int, n)
    }

	for i := 0; i < maxMove; i++ {

        cp := make([][]int, m)
        for i := 0; i < m; i++ {
            cp[i] = make([]int, n)
        }

		for r := 0; r < m; r++ {
			for c := 0; c < n; c++ {
				tt := 0
				for d := 0; d < 4; d++ {
                    rr := r + DR[d]
                    cc := c + DC[d]
                    if rr < 0 || rr > m - 1 || cc < 0 || cc > n - 1 {
                        tt += 1
                        tt %= MOD
                    } else {
                        tt += (dp[rr][cc] % MOD)
                    }
                }
                cp[r][c] = (tt % MOD)
            }
        }
        dp = cp
    }
    return dp[ startRow ][ startColumn ]
}
