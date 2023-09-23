func longestStrChain(words []string) int {
    dp := make(map[string]int)
    res := 1
    sort.Slice(words, func(a, b int) bool {
        return len(words[a]) < len(words[b])
    })
    for _, w := range words {
        for i := 0; i < len(w); i++ {
            s := w[:i] + w[i + 1:]
            if _, ok := dp[w]; !ok {
                dp[w] = 0
            }
            if _, ok := dp[s]; !ok {
                dp[s] = 0
            }
            if dp[w] < dp[s] + 1 {
                dp[w] = dp[s] + 1
            }
        }
        if res < dp[w] {
            res = dp[w]
        }
    }
    return res
}
