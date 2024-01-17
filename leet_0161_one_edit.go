func isOneEditDistance(s string, t string) bool {
    fmt.Println("/Solution_skip_equal_prefix_alt")
	if s == t {
        return false
    }
    i := 0
    for i < len(s) && i < len(t) && s[i] == t[i] {
        i++
    }
    ls, lt := 1, 1
    if len(s) < len(t) {
        ls, lt = 0, 1
    } else if len(t) < len(s) {
        ls, lt = 1, 0
    }
    return s[i+ls:] == t[i+lt:]
}
