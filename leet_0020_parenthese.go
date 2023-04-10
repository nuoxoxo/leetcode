func isValid(s string) bool {
    M := map[rune] rune {
        '(':')',
        '{':'}',
        '[':']',
    }

    D := []rune {}

    for _, c := range s {
        n := len(D)
        if len(D) > 0 && M[D[n - 1]] == c {
            D = D[:n - 1]
        } else {
            D = append(D, c)
        }
    }
    return len(D) == 0
}
