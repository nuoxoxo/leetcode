func searchMatrix(g [][]int, target int) bool {
    r := 0
    c := len(g[0]) - 1
    for r < len(g) && c > -1 {
        if g[r][c] == target {
            return true
        }
        if g[r][c] < target {
            r++
        } else {
            c--
        }
    }
    return false
}
