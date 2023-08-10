func search(nums []int, target int) bool {
	n := len(nums)
	R := n - 1
	L := 0
	if R == 0 {
		if nums[0] == target {
			return true
		}
		return false
	}
	if nums[L] == target || nums[R] == target {
		return true
	}
	for L < R && nums[L] == nums[L+1] {
		L++
	}
	for R > 0 && nums[R] == nums[R-1] {
		R--
	}
	for L < R {
		mid := (L + R) / 2
		if nums[mid] == target {
			return true
		}
		if nums[0] < nums[mid] {
			if nums[0] < target && target < nums[mid] {
				R = mid
			} else {
				L = mid + 1
			}
		} else {
			if nums[mid] < target && target < nums[n-1] {
				L = mid + 1
			} else {
				R = mid
			}
		}
	}
	return false
}

