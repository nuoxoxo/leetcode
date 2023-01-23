function findJudge(n: number, trust: number[][]): number {
    let rr = new Array(n).fill(0)
    let cc = new Array(n).fill(0)
    for (let t of trust) {
        rr[t[0] - 1]++
        cc[t[1] - 1]++
    }
    let i = -1
    while (++i < n) {
        if (rr[i] == 0 && cc[i] == n - 1)
            return i + 1
    }
    return -1

};
