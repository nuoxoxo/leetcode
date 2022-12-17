function fib(n: number): number {
    if (n < 2)
        return n
    let f = new Array(n + 1)
    f[0] = 0
    f[1] = 1
    let i = 1
    while (++i < n + 1) {
        f[i] = f[i - 1] + f[i - 2]
    }
    return f[n ]
};
