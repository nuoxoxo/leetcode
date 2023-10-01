func find132pattern(nums []int) bool {
    mid := math.MinInt64
    D := []int{}
    for i := len(nums) - 1; i > -1; i-- {
        L := nums[i]
        if L < mid {
            return true
        }
        for len(D) > 0 && D[len(D) - 1] < L {
            mid = D[len(D) - 1]
            D = D[:len(D) - 1]
        }
        D = append(D, L)
    }
    return false
}
