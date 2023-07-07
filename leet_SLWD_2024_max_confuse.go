func maxConsecutiveAnswers(s string, k int) int {
    len := len(s)
    res := 0
    t := 0
    f := 0
    l := 0
    r := -1
    for r < len - 1 {
        r++
        if s[r] == 'T' {
            t++
        } else {
            f++
        }
        for t > k && f > k {
            if s[l] == 'T' {
                t--
            } else {
                f--
            }
            l++
        }
        if r - l + 1 > res {
            res = r - l + 1
        }
    }
    return res
}
