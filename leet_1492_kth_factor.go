func kthFactor(n int, k int) int {
    i := 1
    for i < n + 1 {
        if n % i == 0 {
            k--
            if k == 0 {
                return i
            }
        }
        i++
    }
    return -1
}
