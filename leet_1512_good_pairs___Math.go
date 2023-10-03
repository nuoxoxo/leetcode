func numIdenticalPairs(nums []int) int {
    D := map[int]int{}
    // D := make(map[int]int) // different writing
    res := 0
    for _, n := range nums {
        D[n]++
    }
    for _, n := range D {
        res += n * (n - 1) / 2
    }
    return res
}
