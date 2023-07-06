func minSubArrayLen(target int, nums []int) int {
    L := 0
    R := 0
    temp := 0
    found := false
    len := len(nums)
    res := math.MaxInt32
    for R < len {
        temp += nums[R]
        if temp >= target {
            found = true
        }
        for temp >= target {
            if res > R - L + 1 {
                res = R - L + 1
            }
            temp -= nums[L]
            L++
        }
        R++
    }
    if ! found {
        return 0
    }
    return res
}
