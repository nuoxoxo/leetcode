func satisfiesConditions(grid [][]int) bool {

    R := len(grid)
    C := len(grid[0])
    r := 0
    for r < R {
        c := 0
        for c < C {
            if r < R - 1 && grid[r][c] != grid[r + 1][c] {
                return false
            }
            if c < C - 1 && grid[r][c] == grid[r][c + 1] {
                return false
            }
            c++
        }
        r++
    }
    return true
}
