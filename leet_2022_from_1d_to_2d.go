func construct2DArray(original []int, m int, n int) [][]int {
    N := len(original)
    if m * n != N {
        return [][]int{}
    }
    var r, i int
    var res [][]int = make([][]int, m)
    r = 0
    for r < m {
        res[r] = make([]int, n)
        r++
    }
    r = 0
    i = 0
    for r < m {
        c := 0
        for c < n {
            res[r][c] = original[i]
            c++
            i++
        }
        r++
    }
    return res
}
