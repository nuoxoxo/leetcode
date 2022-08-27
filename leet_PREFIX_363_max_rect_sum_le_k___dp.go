func maxSumSubmatrix(grid [][]int, k int) int {
    r := len(grid)
    c := len(grid[0])
    dp := make([][] int, r + 1)
    for i := range dp {
        dp[i] = make([] int, c)
    }
    // fmt.Print(dp)
    for i := 0; i < r; i++ {
        for j := 0; j < c; j++ {
            dp[i + 1][j] = dp[i][j] + grid[i][j]
        }
    }
    // fmt.Print(dp)
    res := -2147483648
    for i := 0; i < r; i++ {
        for ii := i + 1; ii < r + 1; ii++ {
            for j := 0; j < c; j++ {
                tmp := 0
                for jj := j; jj < c; jj++ {
                    tmp += dp[ii][jj] - dp[i][jj] // minus
                    if tmp == k {
                        return k
                    }
                    if tmp < k && res < tmp {
                        res = tmp
                    }
                }
            }
        }
    }
    return res
}

/*
[[1,0,1],[0,-2,3]]
2
[[2,2,-1]]
3
[[2,2,-1]]
0
[[1,0,1],[0,-2,3],[2,6,-6]]
2
[[1,0,1],[0,-2,3],[-10,-12,-1]]
2
*/
