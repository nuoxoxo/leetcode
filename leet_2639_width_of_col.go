func findColumnWidth(grid [][]int) []int {
    c := 0
    var r int
    R := len(grid)
    C := len(grid[0])
    res := []int{}
    for c < C {
        r = 0
        temp := []int{}
        for r < R {
            temp = append(temp, grid[r][c])
            r++
        }
        r = 0
        size := -1
        for r < R {
            sn := len(strconv.Itoa(temp[r]))
            if size < sn {
                size = sn
            }
            r++
        } 
        res = append(res, size)
        c++
    }
    return res
}
