func checkXMatrix(grid [][]int) bool {
    len := len(grid)
    r := 0
    for r < len {
        c := 0
        for c < len {
            if (r == c || c == len - r - 1) && grid[r][c] == 0 {
                return false
            } else if r != c && c != len - r - 1 && grid[r][c] != 0 {
                return false
            }
            c++
        }
        r++
    }
    return true
}
