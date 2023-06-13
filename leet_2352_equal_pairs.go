func equalPairs(grid [][]int) int {
    dict := make(map[string]int)
	len := len(grid)
	cols := make([]string, len)
	res := 0

	for _, nums := range grid {
		s := ""
		for i := 0; i < len; i++ {
			n := nums[i]
			s += " " + fmt.Sprint(n)
			cols[i] += " " + fmt.Sprint(n)
		}

		if _, ok := dict[s]; ok {
			dict[s]++
		} else {
			dict[s] = 1
		}
		// fmt.Println(s, dict[s])
	}

	for _, c := range cols {
		if _, ok := dict[c]; ok {
			res += dict[c]
		}
	}
    return res
}
