func maxSubarrayLength(nums []int, k int) int {
    D := map[int]int{}
    N, l, r := len(nums), 0, 0
    res := -1
    for r < N {
        D[nums[ r ]] += 1
        for D[nums[ r ]] > k {
            D[nums[ l ]] -= 1
            l += 1
        }
        dist := r - l + 1
        if res < dist { res = dist }
        r += 1
    }
    return res
}
