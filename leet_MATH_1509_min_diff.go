func minDifference(nums []int) int {
    N := len(nums)
    if N < 5 {
        return 0
    }
    sort.Ints(nums)
    res := int(math.MaxUint32 >> 1)
    i := 0
    for i < 4 {
        if res > nums[N - 4 + i] - nums[i] {
            res = nums[N - 4 + i] - nums[i]
        }
        i++
    }
    return res
}
