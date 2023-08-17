type Point struct {
    x, y int
}

func updateMatrix(mat [][]int) [][]int {
    r, c := len(mat), len(mat[0])
    dx := []int{  0, 1, 0, -1 }
    dy := []int{ -1, 0, 1, 0  }

    D := make([][]int, r)
    for i := range D {
        D[i] = make([]int, c)
        for j := range D[i] {
            D[i][j] = -1
        }
    }

    var E []Point

    for i := 0; i < r; i++ {
        for j := 0; j < c; j++ {
            if mat[i][j] == 0 {
                E = append(E, Point{ x: i, y: j })
                D[i][j] = mat[i][j]
            }
        }
    }

    for len(E) > 0 {
        tmp := E[0]
        E = E[1:]

        for k := 0; k < 4; k++ {
            tx := tmp.x + dx[k]
            ty := tmp.y + dy[k]
            if tx >= 0 && ty >= 0 && tx < r && ty < c && mat[tx][ty] == 1 && D[tx][ty] == -1 {
                D[tx][ty] = D[tmp.x][tmp.y] + 1
                E = append(E, Point{x: tx, y: ty})
            }
        }
    }

    return D
}
