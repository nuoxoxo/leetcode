func firstMissingPositive(nums []int) int {
    N := len(nums)
    i := 0
    for i < N {
        if 0 < nums[i] && nums[i] <= N && nums[nums[i] - 1] != nums[i] {
            nums[i], nums[nums[i] - 1] = nums[nums[i] - 1], nums[i]
            continue
        }
        i++
    }
    i = 0
    for i < N {
        if nums[i] != i + 1 {
            return i + 1
        }
        i++
    }
    return N + 1
}
