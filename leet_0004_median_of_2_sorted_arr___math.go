func findMedianSortedArrays(nums1 []int, nums2 []int) float64 {

	merged := append(nums1, nums2 ...)
	sort.Ints(merged)
	len := len(merged)
	mid := len / 2
	if len % 2 == 1 {
		return float64(merged[mid])
	}
	return float64(merged[mid - 1] + merged[mid]) / 2.0
}
