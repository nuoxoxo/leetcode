func countPalindromicSubsequence(s string) int {
    D := make (map[byte][2]int)
    size := len(s)
    i := 0
    for i < size {
        c := s[i]
        pair, ok := D[c]
        if ok {
            pair[1] = i
            D[c] = pair
        } else {
            D[c] = [2]int{i, -1}
        }
        i++
    }
    res := 0
    for _, pair := range D {
        l, r := pair[0], pair[1]
        if r == -1 {
            continue
        }
        S := make(map[byte]bool)
        i = l + 1
        for i < r {
            S[s[i]] = true
            i++
        }
        res += len(S)
    }
    return res
}
