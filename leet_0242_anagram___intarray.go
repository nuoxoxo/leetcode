func isAnagram(s string, t string) bool {
    if len(s) == len(t) {
        arr := [26] int {}
        for i := 0; i < len(s); i++ {
            arr[s[i] - 'a']++
            arr[t[i] - 'a']--
        }
        for _, n := range arr {
            if n != 0 {
                return false
            }
        }
        return true
    }
    return false
}
