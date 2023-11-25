func minPairSum(nums []int) int {

    sort.Ints(nums)
    res := 0
    l := 0
    r := len(nums) - 1
    for l < r {
        if res < nums[l] + nums[r] {
            res = nums[l] + nums[r]
        }
        l++
        r--
    }
    return res

    /*
	sort.Ints(nums)

	size := len(nums)
	res := math.MinInt32
	i := 0

	for i < size {
		res = max(res, nums[i] + nums[size - i - 1])
		i++
	}
	return res
    */
}

/*
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
*/
