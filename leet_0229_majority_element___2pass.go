func majorityElement(nums []int) []int {
    var res []int
	var l, lc, r, rc int
	for _, n := range nums {
		if l == n {
			lc++
		} else if r == n {
			rc++
		} else if lc == 0 {
			lc = 1
			l = n
		} else if rc == 0 {
			rc = 1
			r = n
		} else {
			lc--
			rc--
		}
	}
	lc = 0
	rc = 0
	for _, n := range nums {
		if n == l {
			lc++
		} else if n == r {
			rc++
		}
	}
	if lc > len(nums) / 3 {
		res = append(res, l)
	}
	if rc > len(nums) / 3 {
		res = append(res, r)
	}
	return res

}
