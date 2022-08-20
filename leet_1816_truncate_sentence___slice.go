func truncateSentence(s string, k int) string {
    i := 0
    for _, c := range s {
        if c == ' ' {
            k -= 1
            if k == 0 {
                break
            }
        }
        i += 1
    }
    return s[:i]
}
