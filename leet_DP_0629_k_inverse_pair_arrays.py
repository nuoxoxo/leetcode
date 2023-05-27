class Solution:
    def kInversePairs(self, n: int, k: int) -> int:
        mod = 1e9 + 7
        dp = [0] * (k + 1)
        dp[0] = 1
        for i in range(2, n + 1):
            dp2 = [0] * (k + 1)
            dp2[0] = 1
            for j in range(1, k + 1):
                tmp = 0
                if j - i > -1:
                    tmp = dp[j - i]
                dp2[j] = dp2[j - 1] + dp[j] - tmp
            dp = dp2
        return dp[k] % math.floor(mod)
