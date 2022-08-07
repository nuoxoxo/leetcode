class Solution:
    def longestStrChain(self, arr: List[str]) -> int:
        dp = defaultdict(lambda: 0)
        arr.sort(key=len)
        res = 1
        for s in arr:
            for i in range(len(s)):
                tmp = s[:i] + s[i + 1:]
                dp[s] = max(dp[s], dp[tmp] + 1)
            res = max(res, dp[s])
        return res
