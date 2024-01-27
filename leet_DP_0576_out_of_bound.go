func findPaths(m int, n int, maxMove int, startRow int, startColumn int) int {
    Solutions := []func(int, int, int, int, int) int {
        DP_iterative_tabulation,
        DP_recursive_cached_count,
    }
    return Solutions[ rand.Intn(len(Solutions)) ]( m, n, maxMove, startRow, startColumn )
}

func DP_recursive_cached_count(m, n, maxMove, startRow, startColumn int) int {

    fmt.Println("/DP_recursive_cached_count")

    MOD := 1_000_000_007//int(1e9 + 7)
    DR := []int{-1,0,1,0}
    DC := []int{ 0,1,0,-1}

    hasCache := make([][][]bool, m)
	cache := make([][][]int, m)

	for i := 0; i < m; i++ {
		hasCache[i] = make([][]bool, n)
		cache[i] = make([][]int, n)
		for j := 0; j < n; j++ {
			hasCache[i][j] = make([]bool, maxMove + 1)
			cache[i][j] = make([]int, maxMove + 1)
		}
	}

    var dp func(int, int, int) int

	dp = func(r, c int, moves int) int {

		var res int
		if r < 0 || r >= m || c < 0 || c >= n {
			return 1
		} else if moves == maxMove {
			return 0
		}

		if hasCache[r][c][moves] {
			return cache[r][c][moves]
		}

		for i := 0; i < 4; i++ {
			dr := DR[i]
			dc := DC[i]
			res += dp(r + dr, c + dc, moves + 1)
		}

		hasCache[r][c][moves] = true
		cache[r][c][moves] = (res % MOD)
		return res % MOD
	}

	return dp(startRow, startColumn, 0)
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
