func buildArray(target []int, n int) []string {
    res := []string{}
    cur := 0
    i := 1
    for cur != len(target) {
        if target[cur] == i {
            cur++
            res = append(res, "Push")
        } else {
            res = append(res, "Push")
            res = append(res, "Pop")
        }
        i += 1
    }
    return res
}
