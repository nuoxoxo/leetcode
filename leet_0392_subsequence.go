func isSubsequence(s string, t string) bool {
    if s == "" {
        return true
    }
    i, j := 0, 0
    ls, lt := len(s), len(t)
    for i < ls && j < lt {
        if s[i] == t[j] {
            i++
        }
        if i == ls {
            return true
        }
        j++
    }
    return false
}
