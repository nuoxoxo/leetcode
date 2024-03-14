func countSubarrays(nums []int, k int64) int64 {
    var running, res, l, r, N int64
    N = int64(len(nums))
    running = 0
    res = 0
    l, r = 0, 0
    for r < N {
        running += int64(nums[r])
        for running * (r - l + 1) >= k {
            running -= int64(nums[l])
            l++
        }
        res += r - l + 1
        r++
    }
    return res
}
