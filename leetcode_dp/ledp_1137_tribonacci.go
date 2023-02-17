func tribonacci(n int) int {
    if n < 2 {
        return n
    }
    f := make([]int, n + 1)
    f[0] = 0
    f[1] = 1
    f[2] = 1
    i := 3
    for i < n + 1 {
        f[i] = f[i - 1] + f[i - 2] + f[i - 3]
        i++
    }
    return f[n]
}
