func longestSubarray(nums []int) int {
    tt := 1
    L := 0
    R := -1
    for R < len(nums)-1 {
        R++
        if nums[R] == 0 {
            tt--
        }
        if tt < 0 {
            if nums[L] == 0 {
                tt++
            }
            L++
        }
    }
    return len(nums) - 1 - L
}
