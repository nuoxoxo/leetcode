func countNegatives(g [][]int) int {
    r := len(g)
    c := len(g[0])
    i := 0
    j := c - 1
    res := 0
    for i < r && j > -1 {
        if g[i][j] < 0 {
            res += r - i
            j--
        } else {
            i++
        }
    }
    return res

}
