function integerBreak(n: number): number {
    if (n < 4) {
        return n - 1
    }
    let res = 1
    while (n > 4) {
        res *= 3
        n -= 3
    }
    res *= n
    return res
};
