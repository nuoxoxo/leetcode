func subarraySum(nums []int, k int) int {
    prefix := make(map[int]int)
    prefix[0] = 1
    res := 0
    running := 0
    for _, n := range nums {
        running += n
        res += prefix[running - k]
        prefix[running]++
    }
    return res
}
