func isPossibleToSplit(nums []int) bool {

    f := make([]int, 101) // `100` incl.
    for _, n := range nums {
        f[n] += 1
        if f[n] == 3 {
            return false
        }
    }
    return true
}
