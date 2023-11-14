function countPalindromicSubsequence(s: string): number {
    let D: Record<number, number[]> = [] // TS: Record keys are always string
    let len: number = s.length
    let i = -1
    while (++i < len)
    {
        let c = s[i]
        if (D.hasOwnProperty(c)) {
            D[c][1] = i
        } else {
            D[c] = [i, -1]
        }
    }
    let res: number = 0
    for (let [k, v] of Object.entries(D)) {
        let [l, r] = v
        console.log(k, v, l, r)
        if (r == -1)
            continue
        i = l
        let S: Set<string> = new Set()
        while (++i < r) {
            S.add(s[i])
        }
        res += S.size
    }
    return res
};
