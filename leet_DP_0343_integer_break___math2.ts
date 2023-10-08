function integerBreak(n: number): number {
    if (n < 4)
        return n - 1
    let quo:number = Math.floor(n / 3)
    let rem:number = n % 3
    if (rem == 2)
        return Math.pow(3, quo) * 2
    if (rem == 1)
        return Math.pow(3, quo - 1) * 4
    return Math.pow(3, quo)
};
