func decode(encoded []int, first int) []int {
    res := []int{first}
    for _, n := range encoded {
        first ^= n
        res = append(res, first)
    }
    return res
}
