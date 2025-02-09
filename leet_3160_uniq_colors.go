func queryResults(limit int, queries [][]int) []int {
    D := make(map[int]int)
    colors := make(map[int]int)
    curr := 0
    res := make([]int, len(queries))
    for i, q := range queries {
        l,r := q[0], q[1]
        oc := D[l]
        if colors[oc] > 0 {
            colors[oc]--
            if colors[oc] == 0 {
                curr--
            }
        }
        if colors[r] == 0 {
            curr++
        }
        res[i] = curr
        colors[r] ++
        D[l] = r
    }
    return res
}
