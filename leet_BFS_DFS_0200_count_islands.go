func numIslands(grid [][]byte) int {
    Solutions := []func([][]byte) int {
        // Floodfill,
        BFS,
    }
    return Solutions[0](grid)
}

func BFS(G [][]byte) int {

    R := len(G)
	C := len(G[0])
	dr := []int{-1, 0, 1, 0}
	dc := []int{0, 1, 0, -1}
	Seen := make(map[[2]int]bool)
	Q := make([][2]int, 0)
	res := 0

	r := 0
    for r < R {
        c := 0
		for c < C {
			if G[r][c] == '1' && !Seen[[2]int{r, c}] {
				res++
				Seen[[2]int{r, c}] = true
				Q = append(Q, [2]int{r, c})
				for len(Q) > 0 {
					node := Q[0]
					Q = Q[1:]
                    i := 0
					for i < 4 {
						rr := node[0] + dr[i]
						cc := node[1] + dc[i]
						if -1 < rr && rr < R && -1 < cc && cc < C && G[rr][cc] == '1' && !Seen[[2]int{rr, cc}] {
							Q = append(Q, [2]int{rr, cc})
							Seen[[2]int{rr, cc}] = true
						}
                        i++
					}
				}
			}
            c++
		}
        r++
	}
	return res
}

func Floodfill(G [][]byte) int {

    R := len(G)
    C := len(G[0])
    dr := []int{-1, 0, 1, 0}
    dc := []int{0, -1, 0, 1}

    var Flood func(int, int)
    Flood = func(r, c int) {
        if r < 0 || r > R - 1 || c < 0 || c > C - 1 || G[r][c] != '1' {
            return
        }
        G[r][c] = '0'
        i := 0
        for i < 4 {
            Flood(r + dr[i], c + dc[i])
            i++
        }
    }

    res := 0
    r := 0
    for r < R {
        c := 0
        for c < C {
            if G[r][c] == '1' {
                res++
                Flood(r, c)
            }
            c++
        }
        r++
    }
    return res
}
