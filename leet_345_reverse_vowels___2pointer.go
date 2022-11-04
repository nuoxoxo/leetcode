func reverseVowels(s string) string {
    c := [] byte (s)
    for i, j := 0, len(s) - 1; i < j; i, j = i + 1, j - 1  {
        for i < j && ! isvowel(c[i]) {
            i += 1
        }
        for i < j && ! isvowel(c[j]) {
            j -= 1
        }
        if i < j {
            c[i], c[j] = c[j], c[i]
        }
        // i += 1
        // j -= 1
    }
    return string (c)
}

func isvowel(c byte) bool {
    if c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u' && c != 'A' && c != 'E' && c != 'I' && c != 'O' && c != 'U' {
        return false
    }
    return true
}
