func maxMoves(grid [][]int) int {
    R, C := len(grid), len(grid[0])
    DP := make([][]bool, R)
    for r := range DP {
        DP[r] = make([]bool, C)
        DP[r][0] = true
        for c := 1; c < C; c++ { DP[r][c] = false }
    }
    res := 0
    for c := 1; c < C; c++ {
        cc := c - 1
        for r := 0; r < R; r++ {
            if DP[r][cc] && grid[r][cc] < grid[r][c] {
                DP[r][c] = true
            }
            if r > 0 && DP[r - 1][cc] && grid[r - 1][cc] < grid[r][c] {
                DP[r][c] = true
            }
            if r < R - 1 && DP[r + 1][cc] && grid[r + 1][cc] < grid[r][c] {
                DP[r][c] = true
            }
            if DP[r][c] { res = c }
        }
    }
    // for _, line := range DP {fmt.Println("line/", line)}
    return res
    
}
