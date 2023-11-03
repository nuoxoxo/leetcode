func minOperations(nums []int, k int) int {
    ss := make(map[int]bool)
    res := 0
    i := 1
    for i < k + 1 {
        ss[i] = true
        i++
    }
    for len(ss) > 0 {
        n := nums[len(nums) - 1]
        nums = nums[:len(nums) - 1]
        if ss[n] {
            delete(ss, n)
        }
        res++
    }
    return res
}
