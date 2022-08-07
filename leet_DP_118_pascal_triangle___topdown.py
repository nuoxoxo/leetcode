class Solution:
    def generate(self, n: int) -> List[List[int]]:
        dp = [[] for _ in range(n)]
        # print(dp)
        dp[0] = [1]
        if n is 1:
            return dp
        dp[1] = [1, 1]
        if n is 2:
            return dp
        for i in range(2, n):
            for j in range(i + 1):
                if j is 0 or j == i:
                    dp[i].append(1)
                else:
                    tmp = dp[i - 1][j - 1] + dp[i - 1][j]
                    dp[i].append(tmp)
        return dp
