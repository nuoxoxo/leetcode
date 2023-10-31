func findArray(pref []int) []int {
    i := len(pref) - 1
    for i > 0 {
        pref[i] ^= pref[i - 1]
        i--
    }
    return pref
}
