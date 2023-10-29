function countVowelPermutation(n: number): number {

    let [a, e, i, o, u] = [1, 1, 1, 1, 1]
    let mod = Math.floor(1e9 + 7)
    let k = -1
    while (++k < n - 1) {
        let aa = e % mod
        let ee = (a + i) % mod
        let ii = (a + e + o + u) % mod
        let oo = (i + u) % mod
        let uu = a % mod
        a = aa
        e = ee
        i = ii
        o = oo
        u = uu
    }
    return ( a + e + i + o + u ) % mod
    /*

    the 1st way to think about it:

    a       e        i              o        u
    |       |        |              |        |
    e       a, i     a, e, o, u     i, u     a

    */
};
