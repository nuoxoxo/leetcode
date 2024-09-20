func shortestPalindrome(s string) string {
    rev := ""
    N := len(s)
    for i := N - 1; i > -1; i-- {
        rev += string(s[i])
    }
    fmt.Println(rev)
    res := ""
    for i := 0; i < N + 1; i++ {
        // fmt.Println(rev[i:], s[:N - i])
        if rev[i:] == s[:N - i] {
            res = rev[:i] + s
            break
        }
    }
    return res
}
