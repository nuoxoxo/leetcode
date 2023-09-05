func countPairs(nums []int, target int) int {
    l := 0
    r := len(nums) - 1
    res := 0
    sort.Ints(nums)
    for l < r {
        if nums[l] + nums[r] < target {
            res += r - l
            l += 1
        } else {
            r -= 1
        }
    }
    return res
}
