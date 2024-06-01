func numberOfSpecialChars(word string) int {

    U, L := make([]bool, 26), make([]bool, 26)
    for _, c := range word {
        fg := unicode.IsLower(c)
        if fg {
            L[int(c) - 'a'] = true
        } else {
            U[int(c) - 'A'] = true
        }
    }
    res := 0
    i := 0
    for i < 26 {
        if U[i] && L[i] {
            res++
        }
        i++
    }
    return res
}
