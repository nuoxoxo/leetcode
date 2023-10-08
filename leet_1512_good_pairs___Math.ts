function numIdenticalPairs(nums: number[]): number {
    let D: { [key: number]: number } = {}
    let res:number = 0
    for (let n of nums) {
        if (D.hasOwnProperty(n))
            D[n]++
        else
            D[n] = 1
    }
    for (let [_, n] of Object.entries(D)) {
        res += Math.floor(n * (n - 1) / 2)
    }
    return res
};
