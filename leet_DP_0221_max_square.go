func maximalSquare(m [][]byte) int {
    if len(m) < 1 {
        return 0
    }
    R := len(m)
    C := len(m[0])
    DP := make([][]int, R + 1)
    for i := range DP {
        DP[i] = make([]int, C + 1)
    }
    a := 0
    for r := 0; r < R; r++ {
        for c := 0; c < C; c++ {
            if m[r][c] == '1' {
                n := min3(DP[r][c], DP[r + 1][c], DP[r][c + 1]) + 1
                DP[r + 1][c + 1] = n
                a = max2(a, n)
            }
        }
    }
    return a * a
}

func min3(a, b, c int) int {
    if a <= b && a <= c {
        return a
    } else if b <= a && b <= c {
        return b
    }
    return c
}

func max2(a, b int) int {
    if a > b {
        return a
    }
    return b
}
