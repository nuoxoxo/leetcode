func maximumGap(nums []int) int {
    len := len(nums)
    res := 0
    if len < 2 {
        return res
    }
    sort.Ints(nums)
    i := 1
    for i < len {
        res = max(res, nums[i] - nums[i - 1])
        i++
    }
    return res
}
