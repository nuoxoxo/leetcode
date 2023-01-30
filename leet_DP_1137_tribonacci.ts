function tribonacci(n: number): number {
    if (n < 2) {
        return n
    }

    let f = new Array(n + 1).fill(0)
    f[1] = f[2] = 1
    let i = 2
    
    while (++i < n + 1) {
        f[i] = f[i - 3] + f[i - 2] + f[i - 1]
    }
    
    return f[n]
};
