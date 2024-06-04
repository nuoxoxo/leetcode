func longestPalindrome(s string) int {
    D := make(map[rune]int, 0)
    for _, char := range s {
        D[char]++
    }
    res := 0
    mid := false
    for _, v := range D {
        if v % 2 == 1 {
            res += v - 1
            mid = true
        } else {
            res += v
        }
    }
    if mid {
        return res + 1
    }
    return res
}
