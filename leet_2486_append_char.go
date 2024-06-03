func appendCharacters(s string, t string) int {
    is, it := 0, 0
    for is < len(s) && it < len(t) {
        if s[is] == t[it] {
            it++
        }
        is++
    }
    return len(t) - it
}
