func removeDuplicates(s string) string {
    a := [] rune {}
    for _, c := range s {
        if len(a) != 0 && a[len(a) - 1] == c {
            a = a[:len(a) - 1]
        } else {
            a = append(a, c)
        }
    }
    return string (a)
}
