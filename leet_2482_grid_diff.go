func onesMinusZeros(grid [][]int) [][]int {	
    rows := len(grid)
	cols := len(grid[0])
	r, c := 0, 0
	r1 := make([]int, 0)
	r0 := make([]int, 0)
	c0 := make([]int, cols)
	c1 := make([]int, cols)
	res := make([][]int, rows)

	for i := 0; i < rows; i++ {
		res[i] = make([]int, cols)
	}

	for _, row := range grid {
		r1 = append(r1, count(row, 1))
		r0 = append(r0, count(row, 0))
		r = -1
		for r < cols - 1 {
			r++
			if row[r] == 0 {
				c0[r]++
			} else {
				c1[r]++
			}
		}
	}

	r = -1
	for r < rows - 1 {
		r++
		c = -1
		for c < cols - 1 {
			c++
			res[r][c] = r1[r] - r0[r] + c1[c] - c0[c]
		}
	}

	return res
}

//  helper : count occ of an elem

func count(arr []int, target int) int {
	count := 0
	for _, num := range arr {
		if num == target {
			count++
		}
	}
	return count
}
