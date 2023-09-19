func groupThePeople(groupSizes []int) [][]int {
    res := [][]int{}
    D := make(map[int][]int)
    for i := 0; i < len(groupSizes); i++ {
        size := groupSizes[i]
        if _, exists := D[size]; !exists {
            D[size] = []int{}
        }
        D[size] = append(D[size], i)
        if len(D[size]) == size {
            res = append(res, D[size])
            D[size] = []int{}
        }
    }

    return res
}
