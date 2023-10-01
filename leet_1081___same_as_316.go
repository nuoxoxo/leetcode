func smallestSubsequence(s string) string {
    seen := make(map[rune]bool)
    count := make(map[rune]int)
    /*
    seen := [26]int{}
    count := [26]bool{}
    a := 'a'
    */
    res := []rune{}
    for _, c := range s {
        count[c]++
    }
    for _, c := range s {
        if seen[c] {
            count[c] -= 1
        } else {
            for len(res) > 0 && res[len(res) - 1] > c && count[res[len(res) - 1]] > 1 {
                seen[res[len(res) - 1]] = false
                count[res[len(res) - 1]]--
                res = res[:len(res) - 1]
            }
            seen[c] = true
            res = append(res, c)
        }
    }

    return string(res)
}
