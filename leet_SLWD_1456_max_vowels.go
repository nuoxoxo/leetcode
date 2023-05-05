func maxVowels(s string, k int) int {
    v := "aeiou"
    l := 0
    r := 0
    temp := 0
    res := 0
    for r < len(s) {
        if strings.Contains(v, string(s[r])) {
            temp += 1
        }
        if r - l == k {
            if strings.Contains(v, string(s[l])) {
                temp -= 1
            }
            l += 1
        }
        if res < temp {
            res = temp
        }
        r += 1
    }
    return res
}
