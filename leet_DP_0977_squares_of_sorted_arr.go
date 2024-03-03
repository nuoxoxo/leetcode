func sortedSquares(nums []int) []int {
    N := len(nums)
    l, r := 0, N - 1
    res := make([]int, N)
    for l <= r {
        N--
        L, R := abs(nums[l]), abs(nums[r])
        if L < R {
            res[N] = R * R
            r--
        } else {
            res[N] = L * L
            l++
        }
    }
    return res
}

func abs(n int)int{
    if n > 0 {
        return n
    }
    return -n
}
