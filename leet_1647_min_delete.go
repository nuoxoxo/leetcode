func minDeletions(s string) int {
    count := make([]int, 26)
    for _, c := range s {
        count[c - 'a']++
    }
    sort.Ints(count)
    i := 0
    res := 0
    for i < 25 {
        if count[i] == 0 || count[i] != count[i + 1] {
            i++
            continue
        }
        res++
        count[i]--
        i = 0
    }
    return res
}
