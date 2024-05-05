func diStringMatch(s string) []int {

    N := len(s)
    L, R := 0, N
    i := 0
    res := []int{}
    for i < N {
        char := s[i]
        if char == 'I' {
            res = append(res, L)
            L++
        } else if char == 'D' {
            res = append(res, R)
            R--
        }
        i++
    }
    res = append(res, L)
    return res
}
