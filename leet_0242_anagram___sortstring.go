func isAnagram(s string, t string) bool {
    rune1 := [] rune(s)
    rune2 := [] rune(t)
    sort.Slice(rune1, func(x int, y int) bool {
        return rune1[x] < rune1[y]
    })
    sort.Slice(rune2, func(x int, y int) bool {
        return rune2[x] < rune2[y]
    })
    return string(rune1) == string(rune2)
}
