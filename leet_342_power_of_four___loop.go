func isPowerOfFour(n int) bool {
    if n < 1 {
        return false
    }
    for n % 4 == 0 {
        n /= 4
    }
    if n == 1 {
        return true
    }
    return false
}
