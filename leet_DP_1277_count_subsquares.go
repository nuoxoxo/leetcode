func countSquares(matrix [][]int) int {
    R := len(matrix)
    C := len(matrix[0])
    m := [][]int{}
    for r := 0; r < R; r++ {
        temp := []int{}
        for c := 0; c < C; c++ { temp = append(temp, matrix[r][c]) }
        m = append(m, temp)
    }
    res := 0
    for r := 0; r < R; r++ {
        for c := 0; c < C; c++ {
            if r > 0 && c > 0 && m[r][c] > 0 {
                prev := m[r - 1][c - 1]
                if prev > m[r - 1][c] { prev = m[r - 1][c] }
                if prev > m[r][c - 1] { prev = m[r][c - 1] }
                m[r][c] = prev + 1
            }
            res += m[r][c]
        }
    }
    for _, line := range m {fmt.Println("/", line)}
    return res
}
