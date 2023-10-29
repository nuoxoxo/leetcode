/*
2nd way to think about it

a   -   e, i, u
e   -   a, i
i   -   e, o
o   -   i
u   -   i, o
*/

func countVowelPermutation(n int) int {
    a, e, i, o, u := 1, 1, 1, 1, 1
    mod := int(1e9 + 7)
    var aa, ee, ii, oo, uu int

    for k := 0; k < n - 1; k++ {
        aa = (e + i + u) % mod
        ee = (a + i) % mod
        ii = (e + o) % mod
        oo = i % mod
        uu = (i + o) % mod
        a, e, i, o, u = aa, ee, ii, oo, uu
    }

    return (a + e + i + o + u) % mod
}
