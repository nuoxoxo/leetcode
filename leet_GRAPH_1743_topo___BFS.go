func restoreArray(adjacentPairs [][]int) []int {
    D := make(map[int][]int)
	idg := make(map[int]int)

	for _, pair := range adjacentPairs {
		a, b := pair[0], pair[1]
		D[a] = append(D[a], b)
		D[b] = append(D[b], a)
		idg[a]++
		idg[b]++
	}

	res := make([]int, 0, size)
	isFound := false

	// look for the beginning
	var head, tail int
	for k, v := range idg {
		if v == 1 {
			if isFound {
				tail = k
				break
			} else {
				isFound = true
				head = k
			}
		}
	}

	dq := []int{head} // slice is enough for bfs like in python
	index := 0

	for index < len(dq) {
		node := dq[index]
		index++
		res = append(res, node)

		for _, n := range D[node] {
			idg[n]--
			if idg[n] == 1 {
				dq = append(dq, n)
			}
		}
	}

	res = append(res, tail)
	return res
}
