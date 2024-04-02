func isIsomorphic(s string, t string) bool {
    N := len(s)
    if N != len(t) {
        return false
    }
    s2t := make([]int, 128)
    checked := make([]bool, 128)
    i := 0
    for i < N {
        L, R := s[i], t[i]
        if s2t[ L ] != 0 && s2t[ L ] != int(R) {
            return false
        }
        if s2t[ L ] == 0 && checked[ R ] {
            return false
        }
        s2t[ L ] = int( R )
        checked[ R ] = true
        i++
    }
    return true
}
