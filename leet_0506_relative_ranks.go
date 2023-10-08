func findRelativeRanks(score []int) []string {
    sorted := make([]int, len(score))
    copy(sorted, score)
    // sorted := score
    sort.Sort(sort.Reverse(sort.IntSlice(sorted)))
    res := []string{}
    for _, n := range score {
        idx := -1
        for i, val := range sorted {
            if val == n {
                idx = i
                break
            }
        }

        switch idx {
            case 0:
                res = append(res, "Gold Medal")
            case 1:
                res = append(res, "Silver Medal")
            case 2:
                res = append(res, "Bronze Medal")
            default:
                res = append(res, strconv.Itoa(idx + 1))
        }
    }

    return res
}
