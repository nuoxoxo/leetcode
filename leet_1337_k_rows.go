func kWeakestRows(mat [][]int, k int) []int {
    var res []int
	var v [][]int
    len := len(mat)
    i := -1
	for i < len - 1 {
        i++
		temp := 0
		for _, n := range mat[i] {
			temp += n
		}
		v = append(v, []int{temp, i})
	}
	sort.Slice(v, func(i, j int) bool {
		if v[i][0] != v[j][0] {
			return v[i][0] < v[j][0]
		}
		return v[i][1] < v[j][1]
	})
	i = -1
    for i < k - 1 {
        i++
		res = append(res, v[i][1])
	}
	return res
}
