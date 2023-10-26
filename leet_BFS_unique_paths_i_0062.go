func uniquePaths(m int, n int) int {
    g := make([][]int, m)
    for i := range g {
        g[i] = make([]int, n)
        for j := range g[i] {
            g[i][j] = 1
        }
    }

    dq := [][]int{{0, 0}}

    for len(dq) != 0 {
        p := dq[0]
        dq = dq[1:]
        i := p[0]
        j := p[1]

        if i == m || j == n || g[i][j] > 1 {
            continue
        }

        if i > 0 && j > 0 {
            g[i][j] = g[i - 1][j] + g[i][j - 1]
        }

        dq = append(dq, []int{i + 1, j})
        dq = append(dq, []int{i, j + 1})
    }

    return g[m - 1][n - 1]
}
