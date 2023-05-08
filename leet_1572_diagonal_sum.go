func diagonalSum(mat [][]int) int {
    i := 0
    r := 0
    len := len(mat)
    for i < len{
        r += mat[i][i] + mat[i][len - i - 1]
        i++
    }
    if len % 2 == 1 {
        r -= mat[len / 2][len / 2]
    }
    return r
}
