func suggestedProducts(products []string, searchWord string) [][]string {
    sort.Strings(products)
	var res [][]string
	n := len(products)
	wl := len(searchWord)
	L := 0
	R := n - 1
    i := 0
	for i < wl {
		c := searchWord[i]
		for L <= R && (i >= len(products[L]) || products[L][i] < c) {
			L++
		}
		for L <= R && (i >= len(products[R]) || products[R][i] > c) {
			R--
		}
		if L > R {
			res = append(res, []string{})
		} else {
			end := L + 3
			if end > R + 1 {
				end = R + 1
			}
			res = append(res, products[L:end])
		}
        i++
	}
	return res
}
