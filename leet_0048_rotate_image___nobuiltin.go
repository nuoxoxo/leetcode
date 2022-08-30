//

func rotate(g [][]int)  {
    n := len(g)
    for i, _ := range g {
        for j := i + 1; j < n; j++ {
            g[i][j], g[j][i] = g[j][i], g[i][j]
        }
        for x, y := 0, n - 1; x < y; x, y = x + 1, y - 1 {
            g[i][x], g[i][y] = g[i][y], g[i][x]
        }
    }
}
