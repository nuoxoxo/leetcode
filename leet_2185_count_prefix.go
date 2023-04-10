func prefixCount(words [] string, pref string) int {
    res := 0
    for _, w := range words {
        res += helper(w, pref)
    }
    return res
}

func helper(w string, p string) int {
    len1 := len(w)
    len2 := len(p)
    if len1 < len2 {
        return 0
    }
    for i, c := range p {
        if w[i] == byte(c) /* perk */ {
            continue
        }
        return 0
    }
    return 1
}
