func isAnagram(s string, t string) bool {
    if len(s) != len(t) {
        return false
    }
    arr := map[byte] int {}

    // there no while in Go, only do ... while  

    for i := 0; i < len(s); i++ {
        arr[s[i]]++
        arr[t[i]]--
    }
    for _, n := range arr {
        if n != 0 {
            return false
        }
    }
    return true
}
