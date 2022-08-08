func lengthOfLIS(nums []int) int {
    temp := [] int {}
	for _, n := range nums {
        size := len(temp)
		if size == 0 || temp[size - 1] < n {
			temp = append(temp, n)
		} else {
			L := 0
			R := size - 1
			for L < R {
				mid := (R - L) / 2 + L
				if temp[mid] < n {
					L = mid + 1
				} else {
					R = mid
				}
			}
			temp[R] = n
		}
	}
	return len(temp)
}
