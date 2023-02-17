func climbStairs(n int) int {
    if n < 4 {
        return n
    }
    f := make([]int, n)
    f[0] = 1
    f[1] = 2
    f[2] = 3
    i := 3
    for i < n {
        f[i] = f[i - 1] + f[i - 2]
        i++
    }
    return f[n - 1]
}
