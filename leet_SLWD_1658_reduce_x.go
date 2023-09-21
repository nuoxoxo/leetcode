func minOperations(nums []int, x int) int {
    tt := 0
	for _, num := range nums {
		tt += num
	}
	len := len(nums)
	window := -1
	temp := 0
	R := -1
	L := 0
	for R < len - 1 {
		R++
		if R < len {
			temp += nums[R]
		}
		for temp > tt - x && L <= R {
			temp -= nums[L]
			L++
		}
		if temp == tt - x {
			if window < R - L + 1 {
				window = R - L + 1
			}
		}
	}
	if window == -1 {
		return -1
	}
	return len - window
}
