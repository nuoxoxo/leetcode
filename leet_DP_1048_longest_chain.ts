function longestStrChain(words: string[]): number {
    let dp: Record<string, number> = {}
    let res = 1
    words.sort((a, b) => a.length - b.length)
    for (let w of words) {
        let i = -1
        while (++i < w.length) {
            let s = w.slice(0, i) + w.slice(i + 1)
            if (!dp.hasOwnProperty(w))
                dp[w] = 0
            if (!dp.hasOwnProperty(s))
                dp[s] = 0
            dp[w] = Math.max(dp[w], dp[s] + 1)
        }
        res = Math.max(res, dp[w])
    }
    return res
};
