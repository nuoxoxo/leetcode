func numSubseq(nums []int, target int) int {
    sort.Ints(nums)
    res := 0
    mod := 1000000007
    a := []int {1}
    i := 1
    for i < len(nums) {
        a = append(a, a[i - 1] * 2 % mod)
        i++
    }
    l := 0
    r := len(nums) - 1
    for l <= r {
        if nums[l] + nums[r] <= target {
            res = (res + a[r - l]) % mod
            l++
        } else {
            r--
        }
    }
    return res % mod
}
