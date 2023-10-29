/*
the 1st way to think about it:

a       e        i              o        u
|       |        |              |        |
e       a, i     a, e, o, u     i, u     a
*/

func countVowelPermutation(n int) int {
    a, e, i, o, u := 1, 1, 1, 1, 1
    mod := int(1e9 + 7)
    var aa, ee, ii, oo, uu int

    for k := 0; k < n - 1; k++ {
        aa = e % mod
        ee = (a + i) % mod
        ii = (a + o + e + u) % mod
        oo = (i + u) % mod
        uu = a % mod
        a, e, i, o, u = aa, ee, ii, oo, uu
    }

    return (a + e + i + o + u) % mod
}
