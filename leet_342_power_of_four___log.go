func isPowerOfFour(n int) bool {
    if n < 1 {
        return false
    }
    r := math.Log2(float64(n)) / 2
    if math.Ceil(r) == math.Floor(r) {
        return true
    }
    return false
}
