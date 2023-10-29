function countVowelPermutation(n: number): number {

    let [a, e, i, o, u] = [1, 1, 1, 1, 1]
    let mod = Math.floor(1e9 + 7)
    let k = -1
    while (++k < n - 1) {
        let aa = (e + i + u) % mod
        let ee = (a + i) % mod
        let ii = (e + o) % mod
        let oo = (i) % mod
        let uu = (i + o) % mod
        a = aa
        e = ee
        i = ii
        o = oo
        u = uu
    }
    return ( a + e + i + o + u ) % mod
    /*  2nd way to think about it
            a   -   e, i, u
            e   -   a, i
            i   -   e, o
            o   -   i
            u   -   i, o
    */
};
