func rearrangeArray(nums []int) []int {
    var P []int
    var N []int
    for _, n := range nums {
        if n < 0 {
            N = append(N, n)
        } else {
            P = append(P, n)
        }
    }
    i := 0
    res := []int{}
    for i < len(N) {
        res = append(res, P[i])
        res = append(res, N[i])
        i++
    }
    return res
}
