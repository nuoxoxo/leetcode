func truncateSentence(s string, k int) string {
    r := ""
    for _, c := range s {
        if c == ' ' {
            k -= 1
            if k == 0 {
                break
            }
        }
        r += string(c)
    }
    return r
}
