func customSortString(order string, s string) string {
    Solutions := []func(string, string)string{
        Using_map,
    }
    return Solutions[0](order, s)
}

func Using_map(order string, s string) string {
    D := make(map[rune]int)
    for _, c := range s {
        D[c]++
    }
    res := []rune{}
    for _, c := range order {
        n, ok := D[c]
        if ok {
            i := 0
            for i < n {
                res = append(res, c)
                i++
            }
            D[c] = 0
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
