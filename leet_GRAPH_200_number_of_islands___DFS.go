func numIslands(grid [][]byte) int {
    c := len(grid[0])
    r := len(grid)
    count := 0
    for i := 0; i < r; i++ {
        for j := 0; j < c; j++ {
            if grid[i][j] == '1' {
                count ++
                DFS(grid, i, j, r, c)
            }
        }
    }
    return count
}

func DFS(g [][] byte, x int, y int, r int, c int) {
    if x > r - 1 || x < 0 || y > c - 1 || y < 0 || g[x][y] != '1' {
        return
    }
    g[x][y] = ' '
    DFS(g, x + 1, y, r, c)
    DFS(g, x - 1, y, r, c)
    DFS(g, x, y + 1, r, c)
    DFS(g, x, y - 1, r, c)
}
