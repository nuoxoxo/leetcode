func numberOfMatches(n int) int {
    res := 0
    for n != 0 {
        res += n / 2
        n = n / 2 + n % 2
        if n == 1 {
            break
        }
    }
    return res
}
