func twoOutOfThree(nums1 []int, nums2 []int, nums3 []int) []int {
    set := make(map [int] bool)
    for _, n := range nums1 {
        if contains(nums2, n) || contains(nums3, n) {
            set[n] = true
        }
    }
    for _, n := range nums2 {
        if contains(nums3, n) {
            set[n] = true
        }
    }
    res := [] int {}
    for n, b := range set {
        if b {
            res = append(res, n)
        }
    }
    return res
}

// helper
func contains(a []int, key int) bool {
	for _, n := range a {
		if n == key {
			return true
		}
	}
	return false
}
