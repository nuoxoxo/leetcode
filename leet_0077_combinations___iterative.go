func combine(n int, k int) [][]int {
	// var res [][]int // 1st way
    res := make([][]int, 0) // 2nd way
	comb := make([]int, k)
	i := 0

	for i > -1 {
		comb[i]++
		if comb[i] > n {
			i--
			// fmt.Printf("U : i - 1 = %d\n", i)
		} else if i == k-1 {
			res = append(res, append([]int{}, comb...))
			// fmt.Printf("M : ")
			// printer(comb)
		} else {
			fmt.Printf("D(1) : ")
			// printer(comb)
			i++
			comb[i] = comb[i-1]
			// fmt.Printf("D(2) : ")
			// printer(comb)
		}
	}
	return res
}

func printer(comb []int) {
	for _, n := range comb {
		fmt.Printf("%d ", n)
	}
	fmt.Println()
}
