func firstUniqChar(s string) int {
    var dp[26] int
    var i int
    var size int = len(s)
    // fmt.Println(i, size, dp)
    i = 0
    for i < size {
        dp[s[i] - 'a'] += 1
        i++
    }
    i = 0
    for i < size {
        if dp[s[i] - 'a'] == 1 {
            return i
        }
        i++
    }
    return -1
}
