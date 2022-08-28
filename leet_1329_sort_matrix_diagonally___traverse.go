func diagonalSort(mat [][]int) [][]int {
    r := len(mat)
    c := len(mat[0])
    res := make([][] int, r)
    for i := range res {
        res[i] = make([] int, c)
    }
    // fmt.Print(res)
    for d := c * (-1); d < r; d++ {
        temp := [] int {}
        for i := 0; i < r; i++ {
            j := i - d
            if -1 < j && j < c {
                temp = append(temp, mat[i][j])
            }
        }
        sort.Ints(temp)
        t := 0
        for i := 0; i < r; i++ {
            j := i - d
            if -1 < j && j < c {
                res[i][j] = temp[t]
                t++
            }
        }
    }
    return res
}
