func truncateSentence(s string, k int) string {
    ss := strings.Split(s, " ")
    // fmt.Println(ss)
    r := ""
    for _, w := range ss {
        r += w + " "
        k -= 1
        if k == 0 {
            break
        }
    }
    return r[:len(r) - 1]
}
