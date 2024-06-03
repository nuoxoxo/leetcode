func rearrangeCharacters(s string, target string) int {

    var T, S [26]int
    i := 0
    for i < 26 {
        T[i], S[i] = 0, 0
        i++
    }
    res := math.MaxInt32
    for _, c := range s {
        S[c - 'a']++
    }
    for _, c := range target {
        T[c - 'a']++
    }

    i = 0
    for i < 26 {
        if T[i] > 0 {
            Scount := S[i]
            Tcount := T[i]
            res = min(res, Scount / Tcount)
        }
        i++
    }
    return res
}
