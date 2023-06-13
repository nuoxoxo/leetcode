func minPairSum(nums []int) int {
	sort.Ints(nums)

	size := len(nums)
	res := math.MinInt32
	i := 0

	for i < size {
		res = max(res, nums[i] + nums[size - i - 1])
		i++
	}
	return res
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
