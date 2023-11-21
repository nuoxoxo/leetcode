function countNicePairs(nums: number[]): number {
    let res: number = 0
    let D: Record<number, number> = {}
    for (let n of nums) {
        let original = n
        res = 0
        while (n) {
            res = res * 10 + n % 10
            n = Math.floor(n / 10)
        }
        let diff = original - res
        if (D.hasOwnProperty(diff)) {
            D[diff] += 1
        } else {
            D[diff] = 1;
        }
    }
    res = 0
    for (let [_, v] of Object.entries(D)) {
        res = (res + Math.floor(v * (v - 1) / 2)) % (1e9 + 7)
    }
    return res

};
