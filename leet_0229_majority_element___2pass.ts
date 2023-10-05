function majorityElement(nums: number[]): number[] {
    let res:number[] = []
    let [l, lc, r, rc] = [0, 0, 0, 0]
    for (let n of nums) {
        if (l === n) {
            lc++
        } else if (r === n) {
            rc++
        } else if (lc === 0) {
            lc = 1
            l = n
        } else if (rc === 0) {
            rc = 1
            r = n
        } else {
            lc--
            rc--
        }
    }
    lc = 0
    rc = 0
    for (let n of nums) {
        if (n === l) {
            lc++
        } else if (n === r) {
            rc++
        }
    }
    if (lc > Math.floor(nums.length / 3)) {
        res.push(l)
    }
    if (rc > Math.floor(nums.length / 3)) {
        res.push(r)
    }
    return res
};
