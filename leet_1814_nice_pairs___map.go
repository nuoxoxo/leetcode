func countNicePairs(nums []int) int {
    D := make(map[int]int)
	MOD := int(1e9) + 7
	for _, n := range nums {
		original := n
		res := 0
		for n > 0 {
			res = res * 10 + n % 10
			n /= 10
		}
		D[original - res]++
	}
	res := 0
	for _, v := range D {
		res = (res + v * (v - 1) / 2) % MOD
	}
	return res
}
