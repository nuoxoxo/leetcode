func exist(board [][]byte, word string) bool {

    R, C := len(board), len(board[0])
    seen := make([][]bool, R)
    for i := range seen {
        seen[i] = make([]bool, C)
    }
    r := 0
    for r < R {
        c := 0
        for c < C {
            if dfs(board, r, c, word, 0, seen) {
                return true
            }
            c++
        }
        r++
    }
    return false
}

func dfs(g [][]byte, r, c int, s string, idx int, seen [][]bool) bool {

    if idx == len(s) {
        return true
    }
    R, C := len(g), len(g[0])
    if r < 0 || r > R - 1 || c < 0 || c > C - 1 || g[r][c] != s[idx] || seen[r][c] {
        return false
    }

    seen[r][c] = true
    defer func() { seen[r][c] = false }()

    dr := []int{-1, 1, 0, 0}
    dc := []int{0, 0, 1, -1}
    i := 0
    for i < 4 {
        nr, nc := r+dr[i], c+dc[i]
        if dfs(g, nr, nc, s, idx+1, seen) {
            return true
        }
        i++
    }

    // seen[r][c] = false // commented when using `defer`
    return false
}
