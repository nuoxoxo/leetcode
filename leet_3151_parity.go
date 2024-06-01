func isArraySpecial(nums []int) bool {
    i := 0
    for i < len(nums) - 1 {
        if nums[i] & 1 == nums[i + 1] & 1 {
            return false
        }
        i++
    }
    return true

}
