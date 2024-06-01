func duplicateNumbersXOR(nums []int) int {

    res := 0
    S := map[int]bool{}
    for _, n := range nums {
        if S[n] {
            res ^= n
        } else {
            S[n] = true
        }
    }
    return res
}
