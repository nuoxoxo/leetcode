func buddyStrings(s string, g string) bool {
    L := len(s)
    if L != len(g) {
        return false
    }
    if s == g {
        set := make(map[rune]bool)
        for _, ch := range s {
            if set[ch] {
                return true
            }
            set[ch] = true
        }
        return false
    }
    D := []int{}
    for i := 0; i < L; i++ {
        if s[i] != g[i] {
            D = append(D, i)
            if len(D) > 2 {
                return false
            }
        }
    }
    if len(D) != 2 || s[D[0]] != g[D[1]] || s[D[1]] != g[D[0]] {
        return false
    }
    return true
}
