func sortArrayByParity(nums []int) []int {
    n := len(nums)
    i := 0
    j := n - 1
    for i < j {
        for i < j && nums[i] % 2 == 0 {
            i++
        }
        for i < j && nums[j] % 2 == 1 {
            j--
        }
        nums[i], nums[j] = nums[j], nums[i]
    }
    return nums
}
