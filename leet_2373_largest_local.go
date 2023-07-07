func largestLocal(g [][]int) [][]int {
	R := len(g) - 2
	C := len(g[0]) - 2

	res := make([][]int, R)
	for i := range res {
		res[i] = make([]int, C)
	}

	r := -1
	for r < R - 1 {
        r++
		c := -1
		for c < C - 1 {
            c++
			res[r][c] = Max_Local(g, r, c)
		}
	}

	return res
}

// helper

func Max_Local(g [][]int, r int, c int) int {
	res := -1
	rr := r - 1
	cc := 0
	for rr < r + 2 {
		rr++
        cc = c - 1
		for cc < c + 2 {
            cc++
			val := g[rr][cc]
			if val > res {
				res = val
			}
		}
	}
	return res
}
