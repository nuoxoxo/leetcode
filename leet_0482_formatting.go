func licenseKeyFormatting(s string, k int) string {
    s = strings.ToUpper(s)
    N := len(s)
    i := N - 1
    res := ""
    count := 0
    for i > -1 {
        if s[i] == '-' {
            i--
            continue
        }
        if count == k {
            count = 1
            res += "-"
        } else {
            count++
        }
        res += string(rune(s[i]))
        i--
    }
    N = len(res)
    if res != "" && res[N - 1] == '-' {
        res = res[:N - 1]
    }
    return Reverse(res)
}

func Reverse(s string) string {
    N := len(s)
    runes := []rune(s)
    for i, j := 0, N - 1; i < N / 2; i, j = i + 1, j - 1 {
        runes[i], runes[j] = runes[j], runes[i]
    }
    return string( runes )
}
