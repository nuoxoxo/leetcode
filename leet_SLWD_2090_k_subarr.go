func getAverages(nums []int, k int) []int {
    if k == 0 {
        return nums
    }

    window := 1 + k*2
    length := len(nums)
    res := make([]int, length)
    for i := range res {
        res[i] = -1
    }
    if window > length {
        return res
    }
    l := 0
    r := -1
    tt := 0
    avg := 0

    for r < length - 1 {
        r++
        tt += nums[r]
        if r - l + 1 != window {
            continue
        }
        avg = tt / window
        res[r - k] = avg
        tt -= nums[l]
        l++
    }
    return res
}
