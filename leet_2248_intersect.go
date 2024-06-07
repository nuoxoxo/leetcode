func intersection(nums [][]int) []int {
    N := len(nums)
    D := make(map[int]int, 0)
    for _, a := range nums {
        for _, n := range a {
            D[n]++
        }
    }
    res := []int{}
    for k, v := range D {
        if v == N {
            res = append(res, k)
        }
    }
    sort.Ints(res)
    return res
}
