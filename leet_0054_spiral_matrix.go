func spiralOrder(m [][]int) []int {
    res := []int {}
    rows := len(m)
    cols := len(m[0])
    up := 0
    down := rows - 1
    left := 0
    right := cols - 1
    var i int
    for up <= down && left <= right {
        i = left
        for i <= right {
            res = append(res, m[up][i])
            i++
        }
        up++

        i = up
        for i <= down {
            res = append(res, m[i][right])
            i++
        }
        right--

        i = right
        if up <= down {
            for i >= left {
                res = append(res, m[down][i])
                i--
            }
        }
        down--

        i = down
        if left <= right {
            for i >= up {
                res = append(res, m[i][left])
                i--
            }
        }
        left++
    }
    return res
}
