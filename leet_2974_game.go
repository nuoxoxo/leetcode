func numberGame(nums []int) []int {
    sort.Ints(nums)
    i := 0
    for i < len(nums) {
        nums[i], nums[i + 1] = nums[i + 1], nums[i]
        i += 2
    }
    return nums
}
