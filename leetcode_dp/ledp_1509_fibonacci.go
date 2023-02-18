func fib(n int) int {
    if n < 2 {
        return n
    }
    f := make([]int, n + 1)
    f[0] = 0
    f[1] = 1
    for i := 2; i < n + 1; i++ {
        f[i] = f[i - 2] + f[i - 1]
    }
    return f[n]
}
