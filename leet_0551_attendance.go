func checkRecord(s string) bool {

    A := 0
    consecL := 0
    L := 0
    for i := range s {
        c := s[i]
        if c == 'A' {
            A++
        }
        if c == 'L' {
            consecL++
        } else {
            consecL = 0
        }
        if L < consecL {
            L = consecL
        }
    }
    return A < 2 && L < 3
}
