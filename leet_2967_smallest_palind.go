func makeSmallestPalindrome(s string) string {
    R := []rune(rev_str(s))
    S := []rune(s)
    i := 0
    for i < len(s) {
        if R[i] > S[i] {
            R[i] = S[i]
        }
        i++
    }
    return string(R)
}

func rev_str (s string) string {
    runes := []rune{}
    sr := []rune(s)
    i := len(s) - 1
    for i > -1 {
        runes = append(runes, sr[i])
        i--
    }
    return string(runes)
}
