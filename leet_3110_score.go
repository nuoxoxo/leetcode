func scoreOfString(s string) int {

    N := len(s)
    i := 0
    res := 0
    for i < N - 1 {
        n := int(s[i]) - int(s[i + 1])
        fmt.Println(n)
        if n < 0 {
            n = -n
        }
        res += n
        i++
    }
    return res
}
