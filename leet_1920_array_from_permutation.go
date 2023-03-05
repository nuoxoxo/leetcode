func buildArray(nums []int) []int {
    var r [] int
    for i := 0; i < len(nums); i++ {
        r = append(r, nums[nums[i]])
    }
    return r
}
