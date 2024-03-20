class Solution:
    def maxSumAfterPartitioning(self, arr: List[int], k: int) -> int:
        N = len(arr)
        dp = [0] * N
        biggest = arr[0]
        for i in range(k):
            biggest = max(biggest, arr[i])
            dp[i] = biggest * (i + 1)
        for i in range(k, N):
            dp[i] = arr[i] + dp[i - 1]
            biggest = arr[i]
            # back-checking
            for j in range(i - 1, i - k, -1):
                biggest = max(biggest, arr[j])
                dp[i] = max(dp[i], dp[j - 1] + biggest * (i - j + 1))
        return dp[N - 1]

