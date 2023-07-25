func peakIndexInMountainArray(arr []int) int {

	L := 0
	R := len(arr) - 1

	for L <= R {
		mid := (R - L + 1) / 2 + L
		if arr[mid] < arr[mid + 1] {
			L = mid + 1
		} else {
			R = mid - 1
		}
	}
	return L
}

