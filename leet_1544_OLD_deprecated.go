func makeGood(s string) string {
    a := [] rune(s)
    j := -1
    for i := 0; i < len(s); i++ {
        if j == -1 || math.Abs(float64(a[i]) - float64(a[j])) != 32 {
            j += 1
            a[j] = a[i]
        } else {
            j -= 1
        }
    }
    return string(a[0 : j + 1])
}
