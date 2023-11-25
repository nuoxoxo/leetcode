function countHomogenous(s: string): number {
    let MD:number = Math.floor(1e9 + 7)
    let res:number = 0
    let dis:number = 1
    let c:string = s[0]
    let i = 0
    while (++i < s.length) //{
        if (c == s[i]) {
            dis += 1
        } else {
            res += Math.floor((dis * (dis + 1)) / 2) % MD
            dis = 1
            c = s[i]
        }
    // }
    res += Math.floor((dis * (dis + 1)) / 2) % MD
    return res
};
