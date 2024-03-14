func numberOfGoodSubarraySplits(nums []int) int {
    MOD := 1000000007
    N := len(nums)
    l, r, res := 0, 0, 0
    for r < N {
        if nums[r] == 1 {
            res %= MOD
            if res == 0 {
                res = 1
            } else {
                res *= r - l + 1
            }
            l = r + 1
        }
        r++
    }
    return res % MOD
}
