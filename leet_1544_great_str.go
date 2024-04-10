func makeGood(s string) string {
    res := ""
    N := len(s)
    i := 0
    for i < N {
        char := s[i]
        size := len(res)
        if size != 0 && res[size - 1] != char && (res[size - 1] ^ char) == 32 {
            res = res[:size - 1]
        } else {
            res += string(char)
        }
        i++
    }
    return res
}
