func firstUniqChar(s string) int {
    dp := [26] int {}
    // fmt.Println(dp, size, i) // both size . i are depr
    for _, c := range s {
        dp[c - 'a']++
    }
    for i, c := range s {
        if dp[c - 'a'] == 1 {
            return i
        }
    }
    return -1
}
