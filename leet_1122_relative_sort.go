func relativeSortArray(arr1 []int, arr2 []int) []int {
	D := make(map[int]int)
	var tail []int
	var res []int
	var keys []int
	for _, n := range arr1 {
		if !contains(arr2, n) {
			tail = append(tail, n)
		}
	}
	sort.Ints(tail)

	for _, n := range arr2 {
		count := 0
		for _, num := range arr1 {
			if num == n {
				count++
			}
		}
		D[n] = count
		keys = append(keys, n)
	}

	for _, key := range keys {
		temp := make([]int, D[key])
		for i := 0; i < D[key]; i++ {
			temp[i] = key
		}
		res = append(res, temp...)
	}

	return append(res, tail...)
}

func contains(arr []int, target int) bool {
	for _, num := range arr {
		if num == target {
			return true
		}
	}
	return false
}
