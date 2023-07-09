func minOperations(nums []int) int {
    i := 0
    res := 0
    for i < len(nums) - 1 {
        i++
        if nums[i - 1] < nums[i] {
            continue
        }
        temp := nums[i - 1] - nums[i] + 1
        res += temp
        nums[i] = nums[i - 1] + 1
    }
    return res
}
