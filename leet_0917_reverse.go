import "unicode"

func reverseOnlyLetters(s string) string {
    a := []rune(s)
    l := 0
    r := len(a) - 1
    for l < r {
        if unicode.IsLetter(a[l]) && unicode.IsLetter(a[r]) {
            c := a[l]
            a[l] = a[r]
            a[r] = c
            l++
            r--
        } else if ( ! unicode.IsLetter(a[l])) {
            l++
        } else if ( ! unicode.IsLetter(a[r])) {
            r--
        }
    }
    return string(a)
}
