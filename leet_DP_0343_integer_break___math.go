func integerBreak(n int) int {
    if n < 4 {
        return n - 1
    }
    res := 1
    for n > 4 {
        res *= 3
        n -= 3
    }
    res *= n
    return res
}
