func countAsterisks(s string) int {
    incl := true
    res := 0
    for _, c := range s {
        if c == rune('|') {
            incl = ! incl
        }
        if incl && c == rune('*') {
            res++
        }
    }
    return res
}
