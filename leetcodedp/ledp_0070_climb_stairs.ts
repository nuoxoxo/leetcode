function climbStairs(n: number): number {
    if (n < 3) {
        return n
    }
    let f = new Array(n)
    let i = 0
    while (++i < n) {
        if (i < 3)
            f[i - 1] = i
        if (i > 1)
            f[i] = f[i - 1] + f[i - 2]
    }
    return f[n - 1]
};
