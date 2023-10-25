function kthGrammar(n: number, k: number): number {
    let L:number = 1
    let R:number = Math.pow(2, n - 1)
    let res:number = 0
    let i = -1
    while (++i < n - 1) {
        let mid = Math.floor((R - L) / 2) + L
        if (mid < k) {
            L = mid + 1
            res ^= 1
        } else {
            R = mid
        }
    }
    return res
};
