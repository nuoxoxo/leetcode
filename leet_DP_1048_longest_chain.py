class Solution:
    def longestStrChain(self, words: List[str]) -> int:
        dp = defaultdict(int)
        words.sort(key = len)
        res = 1
        for w in words:
            for i in range(len(w)):
                s = w[:i] + w[i + 1:] # s is w minus the char w[i]
                dp[w] = max(dp[w], dp[s] + 1)
            res = max(res, dp[w])
        return res
