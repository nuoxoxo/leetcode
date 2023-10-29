function countBits(n: number): number[] {
    let E: number[] = new Array(n + 1)
    let i = -1
    E.fill(0)
    while (++i < n + 1){
        E[i] = E[Math.floor(i / 2)] + i % 2
    }
    return E
};
