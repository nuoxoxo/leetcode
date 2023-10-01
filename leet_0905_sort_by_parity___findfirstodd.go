func sortArrayByParity(nums []int) []int {
    n := len(nums)
	pos := 0
	i := 0
	for i < n {

		if nums[i]%2 == 0 {
			nums[pos], nums[i] = nums[i], nums[pos]
			pos++
		}
		i++
	}
	return nums
}
