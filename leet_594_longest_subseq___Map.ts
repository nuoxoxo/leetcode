
function findLHS(nums: number[]): number {
    let mp = new Map<number, number>()
    for (let n of nums) {
        if (n in mp)
            mp[n]++
        else
            mp[n] = 1
    }
    // console.log(mp)
    let res = 0
    for (let n of nums) {
        if (n in mp && n + 1 in mp)
            res = Math.max(res, mp[n] + mp[n + 1])
    }
    return res
};
