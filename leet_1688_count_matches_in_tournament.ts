function numberOfMatches(n: number): number {
    let res: number = 0
    while (n) {
        res += Math.floor(n / 2)
        n = Math.floor(n / 2) + n % 2
        if (n == 1) {
            break
        }
    }
    return res
};
