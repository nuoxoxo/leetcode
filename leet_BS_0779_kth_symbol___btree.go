func kthGrammar(n int, k int) int {
    L := 1
    R := int(math.Pow(2, float64(n - 1)))
    res := 0
    i := -1
    for i < n - 2 {
        i++
        mid := (R - L) / 2 + L
        if mid < k {
            L = mid + 1
            res ^= 1
        } else {
            R = mid
        }
    }
    return res
}
