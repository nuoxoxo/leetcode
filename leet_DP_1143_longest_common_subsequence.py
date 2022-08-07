class Solution:
    def longestCommonSubsequence(self, s1: str, s2: str) -> int:
        n1 = len(s1)
        n2 = len(s2)
        dp = [[0] * (1 + n2) for _ in range(1 + n1)]
        i = 1
        while i < n1 + 1:
            j = 1
            while j < n2 + 1:
                if s1[i - 1] == s2[j - 1]:
                    dp[i][j] = dp[i - 1][j - 1] + 1
                else:
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])
                j += 1
            i += 1
        return dp[n1][n2]
