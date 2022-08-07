class Solution:
    def countVowelStrings(self, n: int) -> int:
        dp = [1] * 5
        while n > 0:
            i = 3
            while i > -1:
                dp[i] += dp[i + 1]
                i -= 1
            n -= 1
        # print(dp)
        return dp[0]
