func customSortString(order string, s string) string {
    Solutions := []func(string, string)string{
        // Custom_sort,
        Using_map,
    }
    return Solutions[0](order, s)
}

func Custom_sort(order string, s string) string {

    S := []rune(s)
    sort.SliceStable(S, func(l, r int)bool{
		return strings.IndexRune(order, S[l]) < strings.IndexRune(order, S[r])
	})
    return string(S)
}

func Using_map(order string, s string) string {

    D := make(map[rune]int)
    for _, c := range s {
        D[c]++
    }
    res := []rune{}
    for _, c := range order {
        if n, ok := D[c]; ok {
            i := 0
            for i < n {
                res = append(res, c)
                i++
            }
            delete(D, c)
        }
    }
    for c, n := range D {
        i := 0
        for i < n {
            res = append(res, c)
            i++
        }
    }
    return string(res)
}
