func minimumLength(s string) int {
    N := len(s)
    l, r := 0, N - 1
    for l < r {
        if s[l] == s[r] {
            c := s[l]
            for l <= r && c == s[l] {
                l++
            }
            for l <= r && c == s[r] {
                r--
            }
        } else {
            break
        }
    }
    return r - l + 1
}
