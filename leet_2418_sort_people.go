func sortPeople(names []string, heights []int) []string {
    N := len(names)
    nhs := make([]NH, N)
    // i := 0
    // for i < N {
    for i, name := range names {
        nhs[i] = NH{name, heights[i]}
        i++
    }
    sort.Slice(nhs, func(l, r int) bool {
        return nhs[l].h > nhs[r].h
    })
    res := make([]string, N)
    for i, nh := range nhs {
        res[i] = nh.n
    }
    return res//[]string{}
}

type NH struct {
    n string
    h int
}
